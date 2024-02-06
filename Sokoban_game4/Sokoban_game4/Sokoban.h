#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Collections::Generic;

generic<typename T>
public ref struct Elements
{
    T item;
    Elements^ next;
};

ref class Field;


ref class GameObject
{
protected:
    Point position;
    Image^ img;
    int size;

public:
    GameObject(Point position, Image^ img, int size)
    {
        this->position = position;
        this->img = img;
        this->size = size;
    }

    void Draw(Graphics^ gr)
    {
        gr->DrawImage(img, position.X, position.Y, size, size);
    }

    Point GetPosition()
    {
        return position;
    }

    Image^ GetImage()
    {
        return img;
    }

    int GetSize()
    {
        return size;
    }

    void SetPosition(Point newPosition)
    {
        position = newPosition;
    }

    virtual void SetImage(Image^ newimg)
    {
        img = newimg;
    }
};

ref class Wall : public GameObject
{
public:
    Wall(Point position, Image^ img, int size) : GameObject(position, img, size) {}
};

ref class Place : public GameObject
{
public:
    Place(Point position, Image^ img, int size) : GameObject(position, img, size) { }
};

ref class Box : public GameObject
{
public:
    Box(Point position, Image^ img, int size) : GameObject(position, img, size) { }
};

ref class Men : public GameObject
{
public:
    Men(Point position, Image^ img, int size) : GameObject(position, img, size) { }
};

ref class GameState {
private:
    Elements<Object^>^ fieldState_;
    Point menPosition_;

public:
    GameState(Elements<Object^>^ fieldState, Point menPosition) : fieldState_(fieldState), menPosition_(menPosition) {}

    Elements<Object^>^ GetFieldState()
    {
        return fieldState_;
    }

    Point GetMenPosition()
    {
        return menPosition_;
    }
};

ref class HistoryManager {
private:
    List<GameState^>^ states_;

public:
    HistoryManager()
    {
        states_ = gcnew List<GameState^>();
    }

    void SaveState(Elements<Object^>^ fieldState, Point menPosition)
    {
        Elements<Object^>^ newState = gcnew Elements<Object^>;
        Elements<Object^>^ current = fieldState;
        Elements<Object^>^ newStateCurrent = newState;

        while (current != nullptr)
        {
            Box^ box = dynamic_cast<Box^>(current->item);
            Men^ men = dynamic_cast<Men^>(current->item);
            Place^ place = dynamic_cast<Place^>(current->item);

            if (box != nullptr)
            {
                Box^ clone = gcnew Box(box->GetPosition(), (Image^)box->GetImage()->Clone(), box->GetSize());
                newStateCurrent->item = clone;
            }
            else if (men != nullptr)
            {
                Men^ clone = gcnew Men(men->GetPosition(), (Image^)men->GetImage()->Clone(), men->GetSize());
                newStateCurrent->item = clone;
            }
            else if (place != nullptr)
            {
                Place^ clone = gcnew Place(place->GetPosition(), (Image^)place->GetImage()->Clone(), place->GetSize());
                newStateCurrent->item = clone;
            }
            else {
                newStateCurrent->item = current->item;
            }

            current = current->next;
            if (current != nullptr)
            {
                newStateCurrent->next = gcnew Elements<Object^>;
                newStateCurrent = newStateCurrent->next;
            }
            else
            {
                newStateCurrent->next = nullptr;
            }
        }

        GameState^ gameState = gcnew GameState(newState, menPosition);
        states_->Add(gameState);
    }

    GameState^ Undo()
    {
        if (states_->Count > 0)
        {
            GameState^ lastState = states_[states_->Count - 1];
            states_->RemoveAt(states_->Count - 1);
            return lastState;
        }
        else
        {
            return nullptr;
        }
    }

    int GetStateCount()
    {
        return states_->Count;
    }
};

ref class Field
{
private:
    int _width;
    int _height;
    PictureBox^ MyField;
    HistoryManager^ historyManager_;
    bool ok;

public:
    Elements<Object^>^ first;

    Field(PictureBox^ mf)
    {
        MyField = mf;
        MyField->Hide();
        MyField->BackColor = Color::Gray;
        _width = mf->Width;
        _height = mf->Height;
        historyManager_ = gcnew HistoryManager();
        ok = false;
    }

    Men^ GetMen()
    {
        Elements<Object^>^ temp = first;
        while (temp != nullptr)
        {
            Men^ men = dynamic_cast<Men^>(temp->item);
            if (men != nullptr)
            {
                return men;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    void Add(Object^ obj)
    {
        Elements<Object^>^ temp = gcnew Elements<Object^>;
        temp->item = obj;
        temp->next = first;
        first = temp;
    }

    bool MoveBox(int deltaX, int deltaY, Box^ box)
    {
        int newPosX = box->GetPosition().X + deltaX;
        int newPosY = box->GetPosition().Y + deltaY;
        Point newPos = Point(newPosX, newPosY);

        Elements<Object^>^ temp = first;
        while (temp != nullptr)
        {
            Box^ otherBox = dynamic_cast<Box^>(temp->item);
            Wall^ wall = dynamic_cast<Wall^>(temp->item);

            if (otherBox != nullptr && otherBox != box && otherBox->GetPosition() == newPos)
            {
                return false;
            }
            else if (wall != nullptr && wall->GetPosition() == newPos)
            {
                return false;
            }
            temp = temp->next;
        }
        box->SetPosition(newPos);

        if (IsBoxOnPlace(box))
        {
            Image^ newImg = gcnew Bitmap("images\\Box_active.png");
            box->SetImage(newImg);
        }
        else
        {
            Image^ newImg = gcnew Bitmap("images\\Box.png");
            box->SetImage(newImg);
        }
        return true;
    }

    bool CheckWin()
    {
        Elements<Object^>^ temp = first;
        while (temp != nullptr)
        {
            Box^ box = dynamic_cast<Box^>(temp->item);
            if (box != nullptr)
            {
                Point boxPos = box->GetPosition();

                Elements<Object^>^ temp2 = first;
                bool isOnPlace = false;
                while (temp2 != nullptr)
                {
                    Place^ place = dynamic_cast<Place^>(temp2->item);
                    Point adjustedBoxPos = Point(boxPos.X + 12, boxPos.Y + 12);
                    if (place != nullptr && place->GetPosition() == adjustedBoxPos)
                    {
                        isOnPlace = true;
                        break;
                    }
                    temp2 = temp2->next;
                }

                if (!isOnPlace)
                {
                    return false;
                }
            }
            temp = temp->next;
        }
        return true;
    }

    bool IsBoxOnPlace(Box^ box)
    {
        Point boxPos = box->GetPosition();
        Elements<Object^>^ temp = first;
        while (temp != nullptr)
        {
            Place^ place = dynamic_cast<Place^>(temp->item);
            Point adjustedBoxPos = Point(boxPos.X + 12, boxPos.Y + 12);
            if (place != nullptr)
            {
                if (place->GetPosition() == adjustedBoxPos)
                {
                    Image^ newImg = gcnew Bitmap("images\\transparent.png");
                    place->SetImage(newImg);
                    return true;
                }
                else
                {
                    Image^ newImg1 = gcnew Bitmap("images\\Place.png");
                    place->SetImage(newImg1);
                }
            }
            temp = temp->next;
        }
        return false;
    }

    void UndoMove() 
    {
        GameState^ previousState = historyManager_->Undo();
        if (previousState != nullptr) 
        {
            first = previousState->GetFieldState();
            this->GetMen()->SetPosition(previousState->GetMenPosition());
            Draw();
        }
    }

    void UndoFirst()
    {
        while (historyManager_->GetStateCount() > 0)
        {
            GameState^ state = historyManager_->Undo();
            if (state != nullptr)
            {
                first = state->GetFieldState();
                this->GetMen()->SetPosition(state->GetMenPosition());
                Draw();
            }
        }
    }

    void MoveMen(Object^ sender, KeyEventArgs^ e, int Size_Object)
    {
        if (ok) return;
        int deltaX = 0;
        int deltaY = 0;

        switch (e->KeyCode)
        {
            case Keys::D:
            {
                deltaX = Size_Object;
                break;
            }
            case Keys::A:
            {
                deltaX = -Size_Object;
                break;
            }
            case Keys::S:
            {
                deltaY = Size_Object;
                break;
            }
            case Keys::W:
            {
                deltaY = -Size_Object;
                break;
            }
        }

        historyManager_->SaveState(first, this->GetMen()->GetPosition());
        
        bool canMove = true;
        Box^ boxToMove = nullptr;

        Elements<Object^>^ temp = first;
        Men^ men = this->GetMen();
        while (temp != nullptr)
        {
            Box^ box = dynamic_cast<Box^>(temp->item);
            Wall^ wall = dynamic_cast<Wall^>(temp->item);

            if (box != nullptr && box->GetPosition() == Point(men->GetPosition().X + deltaX, men->GetPosition().Y + deltaY))
            {
                canMove = MoveBox(deltaX, deltaY, box);
                boxToMove = box;
                break;
            }
            else if (wall != nullptr && wall->GetPosition() == Point(men->GetPosition().X + deltaX, men->GetPosition().Y + deltaY))
            {
                canMove = false;
                break;
            }
            temp = temp->next;
        }

        if (canMove)
        {
            men->SetPosition(Point(men->GetPosition().X + deltaX, men->GetPosition().Y + deltaY));
        }

        Draw();

        if (CheckWin())
        {
            MessageBox::Show("Congratulations, you won!", "Game Over", MessageBoxButtons::OK);
            ok = true;
        }
    }

    void Draw()
    {
        Bitmap^ bmp = gcnew Bitmap(MyField->Width, MyField->Height);
        Graphics^ g = Graphics::FromImage(bmp);
        g->Clear(MyField->BackColor);
        Elements<Object^>^ temp = first;
        while (temp != nullptr)
        {
            GameObject^ gameObject = dynamic_cast<GameObject^>(temp->item);
            if (gameObject != nullptr)
            {
                gameObject->Draw(g);
            }

            temp = temp->next;
        }
        MyField->Image = bmp;
    }

};
