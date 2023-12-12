#pragma once
#include <iostream>
#include "httplib.h"
#include <msclr/marshal_cppstd.h>
#include "HTTP_Client.h"
#include "Socket_Client.h"
#include "Client.h"


namespace lab9 {
  Client* client;

  using namespace System;
  using namespace System::ComponentModel;
  using namespace System::Collections;
  using namespace System::Windows::Forms;
  using namespace System::Data;
  using namespace System::Drawing;

  /// <summary>
  /// Summary for MainForm
  /// </summary>
  public ref class MainForm : public System::Windows::Forms::Form
  {
  public:

    static MainForm^ mainForm;

    MainForm(void)
    {
      InitializeComponent();
      //
      //TODO: Add the constructor code here
      //
    }

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~MainForm()
    {
      if (components)
      {
        delete components;
      }
    }
  private: System::Windows::Forms::TextBox^ message_to_send_textBox;
  protected:

  private: System::Windows::Forms::Button^ send_button;
  private: System::Windows::Forms::TextBox^ ip_textBox;
  protected:


  private: System::Windows::Forms::TextBox^ port_textBox;

  private: System::Windows::Forms::Button^ connect_button;

  private: System::Windows::Forms::Label^ label1;
  private: System::Windows::Forms::Label^ label2;
  private: System::Windows::Forms::TextBox^ chat_textBox;
  private: System::Windows::Forms::CheckBox^ checkBox1;


  private:
    /// <summary>
    /// Required designer variable.
    /// </summary>
    System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    void InitializeComponent(void)
    {
      this->message_to_send_textBox = (gcnew System::Windows::Forms::TextBox());
      this->send_button = (gcnew System::Windows::Forms::Button());
      this->ip_textBox = (gcnew System::Windows::Forms::TextBox());
      this->port_textBox = (gcnew System::Windows::Forms::TextBox());
      this->connect_button = (gcnew System::Windows::Forms::Button());
      this->label1 = (gcnew System::Windows::Forms::Label());
      this->label2 = (gcnew System::Windows::Forms::Label());
      this->chat_textBox = (gcnew System::Windows::Forms::TextBox());
      this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
      this->SuspendLayout();
      // 
      // message_to_send_textBox
      // 
      this->message_to_send_textBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)),
        static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(32)));
      this->message_to_send_textBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
      this->message_to_send_textBox->ForeColor = System::Drawing::Color::White;
      this->message_to_send_textBox->Location = System::Drawing::Point(12, 496);
      this->message_to_send_textBox->Multiline = true;
      this->message_to_send_textBox->Name = L"message_to_send_textBox";
      this->message_to_send_textBox->Size = System::Drawing::Size(408, 49);
      this->message_to_send_textBox->TabIndex = 0;
      // 
      // send_button
      // 
      this->send_button->Location = System::Drawing::Point(416, 496);
      this->send_button->Name = L"send_button";
      this->send_button->Size = System::Drawing::Size(51, 49);
      this->send_button->TabIndex = 1;
      this->send_button->Text = L"send";
      this->send_button->UseVisualStyleBackColor = true;
      this->send_button->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
      // 
      // ip_textBox
      // 
      this->ip_textBox->Location = System::Drawing::Point(12, 33);
      this->ip_textBox->Multiline = true;
      this->ip_textBox->Name = L"ip_textBox";
      this->ip_textBox->Size = System::Drawing::Size(174, 37);
      this->ip_textBox->TabIndex = 2;
      // 
      // port_textBox
      // 
      this->port_textBox->Location = System::Drawing::Point(192, 33);
      this->port_textBox->Multiline = true;
      this->port_textBox->Name = L"port_textBox";
      this->port_textBox->Size = System::Drawing::Size(111, 37);
      this->port_textBox->TabIndex = 3;
      // 
      // connect_button
      // 
      this->connect_button->Location = System::Drawing::Point(308, 33);
      this->connect_button->Name = L"connect_button";
      this->connect_button->Size = System::Drawing::Size(78, 37);
      this->connect_button->TabIndex = 4;
      this->connect_button->Text = L"connect";
      this->connect_button->UseVisualStyleBackColor = true;
      this->connect_button->Click += gcnew System::EventHandler(this, &MainForm::connect_button_Click);
      // 
      // label1
      // 
      this->label1->AutoSize = true;
      this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
      this->label1->Location = System::Drawing::Point(54, 14);
      this->label1->Name = L"label1";
      this->label1->Size = System::Drawing::Size(82, 16);
      this->label1->TabIndex = 5;
      this->label1->Text = L"IPv4 Adress:";
      // 
      // label2
      // 
      this->label2->AutoSize = true;
      this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
      this->label2->Location = System::Drawing::Point(224, 14);
      this->label2->Name = L"label2";
      this->label2->Size = System::Drawing::Size(34, 16);
      this->label2->TabIndex = 6;
      this->label2->Text = L"Port:";
      // 
      // chat_textBox
      // 
      this->chat_textBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
        static_cast<System::Int32>(static_cast<System::Byte>(32)));
      this->chat_textBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
      this->chat_textBox->ForeColor = System::Drawing::Color::White;
      this->chat_textBox->Location = System::Drawing::Point(12, 86);
      this->chat_textBox->Multiline = true;
      this->chat_textBox->Name = L"chat_textBox";
      this->chat_textBox->ReadOnly = true;
      this->chat_textBox->Size = System::Drawing::Size(454, 404);
      this->chat_textBox->TabIndex = 7;
      // 
      // checkBox1
      // 
      this->checkBox1->AutoSize = true;
      this->checkBox1->ForeColor = System::Drawing::Color::White;
      this->checkBox1->Location = System::Drawing::Point(391, 42);
      this->checkBox1->Name = L"checkBox1";
      this->checkBox1->Size = System::Drawing::Size(75, 20);
      this->checkBox1->TabIndex = 8;
      this->checkBox1->Text = L"use http";
      this->checkBox1->UseVisualStyleBackColor = true;
      // 
      // MainForm
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(8)), static_cast<System::Int32>(static_cast<System::Byte>(8)),
        static_cast<System::Int32>(static_cast<System::Byte>(8)));
      this->ClientSize = System::Drawing::Size(479, 557);
      this->Controls->Add(this->checkBox1);
      this->Controls->Add(this->chat_textBox);
      this->Controls->Add(this->label2);
      this->Controls->Add(this->label1);
      this->Controls->Add(this->connect_button);
      this->Controls->Add(this->port_textBox);
      this->Controls->Add(this->ip_textBox);
      this->Controls->Add(this->send_button);
      this->Controls->Add(this->message_to_send_textBox);
      this->Name = L"MainForm";
      this->Text = L"MainForm";
      this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::MyForm_Paint);
      this->ResumeLayout(false);
      this->PerformLayout();

    }
#pragma endregion


  private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
  {
    std::string user_message = msclr::interop::marshal_as<std::string>(message_to_send_textBox->Text + "\r\n");
    std::cout << "button1_Click: " << user_message << std::endl;
    client->SendMessage(user_message);
    message_to_send_textBox->Text = "";
  }

  private: bool DoesIpValid(std::string ip)
  {
    return true;
  }

  private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
  {
    if (client == nullptr)
    {
      return;
    }
    if (client->chat.empty())
    {
      return;
    }
    //std::cout<< client->chat<<std::endl;
    chat_textBox->Text = msclr::interop::marshal_as<String^>(client->chat);
  }

  private: System::Void connect_button_Click(System::Object^ sender, System::EventArgs^ e) {

    std::string server_ip = msclr::interop::marshal_as<std::string>(ip_textBox->Text);
    std::string server_port = msclr::interop::marshal_as<std::string>(port_textBox->Text);

    if (!DoesIpValid(server_ip))
    {
      //show error message
      return;
    }

    if (checkBox1->Checked)
    {
      client = new HTTP_Client;
    }
    else
    {
      client = new Socket_Client;
    }


    client->Initialize(server_ip, std::stoi(server_port));
  }
  };
}
