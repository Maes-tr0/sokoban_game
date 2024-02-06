#pragma once
#include"Sokoban.h"

namespace Sokobangame4 {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
	using namespace System::Data;
	using namespace System::Collections;
	using namespace System::ComponentModel;


	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			fd = gcnew Field(pictureBox1);
			AddPole();
			this->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &MyForm::MyForm_PreviewKeyDown);
			this->KeyDown += gcnew KeyEventHandler(this, &MyForm::MyForm_KeyDown);
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::PictureBox^ pictureBox1;
		System::ComponentModel::Container^ components;
		System::Windows::Forms::Button^ button1;

		System::Windows::Forms::Button^ button3;
		System::Windows::Forms::Button^ button4;
		System::Windows::Forms::Button^ button5;
		System::Windows::Forms::Button^ button6;
		System::Windows::Forms::Button^ button7;
	    Field^ fd;
		
		System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
			fd->Draw();
		}

		System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
		{
			fd->MoveMen(sender, e, 50);
		}

		void AddPole()
		{
			Image^ menImage = gcnew Bitmap("images\\Men.png");
			Image^ boxImage = gcnew Bitmap("images\\Box.png");
			Image^ wallImage = gcnew Bitmap("images\\Wall.png");
			Image^ palceImage = gcnew Bitmap("images\\Place.png");
			Men^ men = gcnew Men(Point(100, 100), menImage, 50);

			Place^ pl1 = gcnew Place(Point(50 + 12, 100 + 12), palceImage, 25);
			Place^ pl2 = gcnew Place(Point(50 + 12, 200 + 12), palceImage, 25);
			Place^ pl3 = gcnew Place(Point(250 + 12, 150 + 12), palceImage, 25);
			Place^ pl4 = gcnew Place(Point(200 + 12, 250 + 12), palceImage, 25);
			Place^ pl5 = gcnew Place(Point(200 + 12, 350 + 12), palceImage, 25);
			Place^ pl6 = gcnew Place(Point(150 + 12, 300 + 12), palceImage, 25);
			Place^ pl7 = gcnew Place(Point(300 + 12, 300 + 12), palceImage, 25);

			Box^ box1 = gcnew Box(Point(150, 100), boxImage, 50);
			Box^ box2 = gcnew Box(Point(200, 150), boxImage, 50);
			Box^ box3 = gcnew Box(Point(200, 200), boxImage, 50);
			Box^ box4 = gcnew Box(Point(50, 300), boxImage, 50);
			Box^ box5 = gcnew Box(Point(150, 300), boxImage, 50);
			Box^ box6 = gcnew Box(Point(200, 300), boxImage, 50);
			Box^ box7 = gcnew Box(Point(250, 300), boxImage, 50);

			Wall^ wall1 = gcnew Wall(Point(0, 50), wallImage, 50);
			Wall^ wall2 = gcnew Wall(Point(0, 100), wallImage, 50);
			Wall^ wall3 = gcnew Wall(Point(0, 150), wallImage, 50);
			Wall^ wall4 = gcnew Wall(Point(0, 200), wallImage, 50);
			Wall^ wall5 = gcnew Wall(Point(0, 250), wallImage, 50);
			Wall^ wall6 = gcnew Wall(Point(0, 300), wallImage, 50);
			Wall^ wall7 = gcnew Wall(Point(0, 350), wallImage, 50);
			Wall^ wall8 = gcnew Wall(Point(0, 400), wallImage, 50);
			Wall^ wall9 = gcnew Wall(Point(50, 50), wallImage, 50);
			Wall^ wall10 = gcnew Wall(Point(100, 50), wallImage, 50);
			Wall^ wall11 = gcnew Wall(Point(100, 0), wallImage, 50);
			Wall^ wall12 = gcnew Wall(Point(150, 0), wallImage, 50);
			Wall^ wall13 = gcnew Wall(Point(200, 0), wallImage, 50);
			Wall^ wall14 = gcnew Wall(Point(250, 0), wallImage, 50);
			Wall^ wall15 = gcnew Wall(Point(300, 0), wallImage, 50);
			Wall^ wall16 = gcnew Wall(Point(50, 400), wallImage, 50);
			Wall^ wall17 = gcnew Wall(Point(100, 400), wallImage, 50);
			Wall^ wall18 = gcnew Wall(Point(150, 400), wallImage, 50);
			Wall^ wall19 = gcnew Wall(Point(200, 400), wallImage, 50);
			Wall^ wall20 = gcnew Wall(Point(250, 400), wallImage, 50);
			Wall^ wall21 = gcnew Wall(Point(300, 400), wallImage, 50);
			Wall^ wall22 = gcnew Wall(Point(350, 400), wallImage, 50);
			Wall^ wall23 = gcnew Wall(Point(350, 350), wallImage, 50);
			Wall^ wall24 = gcnew Wall(Point(350, 300), wallImage, 50);
			Wall^ wall25 = gcnew Wall(Point(350, 250), wallImage, 50);
			Wall^ wall26 = gcnew Wall(Point(300, 250), wallImage, 50);
			Wall^ wall27 = gcnew Wall(Point(300, 200), wallImage, 50);
			Wall^ wall28 = gcnew Wall(Point(300, 150), wallImage, 50);
			Wall^ wall29 = gcnew Wall(Point(300, 100), wallImage, 50);
			Wall^ wall30 = gcnew Wall(Point(300, 50), wallImage, 50);
			Wall^ wall31 = gcnew Wall(Point(50, 150), wallImage, 50);
			Wall^ wall32 = gcnew Wall(Point(100, 150), wallImage, 50);
			Wall^ wall33 = gcnew Wall(Point(100, 200), wallImage, 50);
			Wall^ wall34 = gcnew Wall(Point(150, 200), wallImage, 50);
			Wall^ wall35 = gcnew Wall(Point(100, 250), wallImage, 50);


			fd->Add(men);

			fd->Add(wall1);
			fd->Add(wall2);
			fd->Add(wall3);
			fd->Add(wall4);
			fd->Add(wall5);
			fd->Add(wall6);
			fd->Add(wall7);
			fd->Add(wall8);
			fd->Add(wall9);
			fd->Add(wall10);
			fd->Add(wall11);
			fd->Add(wall12);
			fd->Add(wall13);
			fd->Add(wall14);
			fd->Add(wall15);
			fd->Add(wall16);
			fd->Add(wall17);
			fd->Add(wall18);
			fd->Add(wall19);
			fd->Add(wall20);
			fd->Add(wall21);
			fd->Add(wall22);
			fd->Add(wall23);
			fd->Add(wall24);
			fd->Add(wall25);
			fd->Add(wall26);
			fd->Add(wall27);
			fd->Add(wall28);
			fd->Add(wall29);
			fd->Add(wall30);
			fd->Add(wall31);
			fd->Add(wall32);
			fd->Add(wall33);
			fd->Add(wall34);
			fd->Add(wall35);

			fd->Add(box1);
			fd->Add(box2);
			fd->Add(box3);
			fd->Add(box4);
			fd->Add(box5);
			fd->Add(box6);
			fd->Add(box7);

			fd->Add(pl1);
			fd->Add(pl2);
			fd->Add(pl3);
			fd->Add(pl4);
			fd->Add(pl5);
			fd->Add(pl6);
			fd->Add(pl7);
		}

#pragma region Windows Form Designer generated code


		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->pictureBox1->Location = System::Drawing::Point(431, 65);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(399, 448);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::IndianRed;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"SimSun", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(74, 448);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(208, 65);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Start Game";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Maroon;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Font = (gcnew System::Drawing::Font(L"SimSun", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(93, 529);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(167, 41);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Exit";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::IndianRed;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button4->Font = (gcnew System::Drawing::Font(L"SimSun", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(959, 235);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(195, 60);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Previous move";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::IndianRed;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button5->Font = (gcnew System::Drawing::Font(L"SimSun", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(973, 310);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(169, 41);
			this->button5->TabIndex = 5;
			this->button5->Text = L"Restart Game";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::Maroon;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button6->Font = (gcnew System::Drawing::Font(L"SimSun", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(1212, 12);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(38, 33);
			this->button6->TabIndex = 6;
			this->button6->Text = L"X";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::IndianRed;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button7->Font = (gcnew System::Drawing::Font(L"SimSun", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(973, 368);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(169, 40);
			this->button7->TabIndex = 7;
			this->button7->Text = L"Menu";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// MyForm
			// 
			this->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1262, 673);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			button4->Hide();
			button5->Hide();
			button6->Hide();
			button7->Hide();
			this->Font = (gcnew System::Drawing::Font(L"SimSun", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Sokoban";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
		{
			fd->UndoFirst();
			pictureBox1->Show();
			this->KeyPreview = true;
			button4->Show();
			button5->Show();
			button6->Show();
			button7->Show();
			button1->Hide();
			button3->Hide();
		}
		private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Close();
		}
		private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e)
		{
			fd->UndoMove();
		}
		private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e)
		{
			fd->UndoFirst();
		}
		private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			Close();
		}
		private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e)
		{
			button1->Show();
			button3->Show();
			pictureBox1->Hide();
			button4->Hide();
			button5->Hide();
			button6->Hide();
			button7->Hide();
		}
		private: System::Void MyForm_PreviewKeyDown(Object^ sender, System::Windows::Forms::PreviewKeyDownEventArgs^ e)
		{
			if (e->KeyCode == Keys::Up || e->KeyCode == Keys::Down || e->KeyCode == Keys::Left || e->KeyCode == Keys::Right)
			{
				e->IsInputKey = true;
			}
		}
	};
};