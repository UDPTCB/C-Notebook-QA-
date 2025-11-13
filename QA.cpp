// QA.cpp: 定义应用程序的入口点。
//Make from Doe in Sat, 8 11 2025 UTC+8

#include "QA.h"
namespace fs = std::filesystem;

using namespace std;
/*static void test() {
	struct data1 {
	string data;
	string name;
	};
	
	auto ptrx = std::make_unique <data1>(data1{ "a", "b" });
	
	cout << ptrx->data << endl;
}
*/


class save{
private:
	//string data;
	//string path;
	struct f1 {
		string data;
		string path;
		string newpath;
	};
	std::unique_ptr<f1> ptr1;
	
	
public:
	void setdata(string d,string n){
		ptr1 = std::make_unique<f1>(f1{ d, n });
	}
	void rename(string on, string nm) {
		ptr1 = std::make_unique<f1>(f1{ "", on, nm });
	}
	bool rent() {
		try {
			fs::path q;
			fs::path p;
			if (!fs::exists(fs::path("D:\\database\\"))) {
				q = fs::path("C:\\database\\" + ptr1->path + ".txt");
			}
			else {
				q = fs::path("D:\\database\\" + ptr1->path + ".txt");
			}
			if (!fs::exists(fs::path("D:\\database\\"))) {
				p = fs::path("C:\\database\\" + ptr1->newpath + ".txt");
			}
			else {
				p = fs::path("D:\\database\\" + ptr1->newpath + ".txt");
			}
			if (fs::exists(q)) {
				fs::rename(q,p);

				return true;
			}
			else {
				cout << "The file does not exist!" << endl;
				return false;
			}
		}
		catch (const std::exception& e) {
			cout << "An error occurred: " << e.what() << endl;
			return false;
		}
	}
	bool save2() {
		try {
				fs::path q;
				if (!fs::exists(fs::path("D:\\database\\"))) {
					q = fs::path("C:\\database\\" + ptr1->path + ".txt");
				}
				else {
					q = fs::path("D:\\database\\" + ptr1->path + ".txt");
				}
				fstream out(q, ios::out);
				if (!out) {
					cout << "The file could not be opened!" << endl;
				
					return false;
				}
				else {
					out << ptr1->data << endl;
					out.close();
				
					return true;
				}
			}
			catch (const std::exception& e) {
				cout << "An error occurred: " << e.what() << endl;
			
				return false;
			}
	}
	bool save1() {
		try {
			fs::path q;
			if (!fs::exists(fs::path("D:\\database\\"))) {
				q = fs::path("C:\\database\\" + ptr1->path + ".txt");
			}
			else {
				q = fs::path("D:\\database\\" + ptr1->path + ".txt");
			}
			fstream out(q, ios::app);
			if (!out) {
				cout << "The file could not be opened!" << endl;

				return false;
			}
			else {
				out << ptr1->data << endl;
				out.close();

				return true;
			}
		}
		catch (const std::exception& e) {
			cout << "An error occurred: " << e.what() << endl;

			return false;
		}
	}
	bool read1() {
		try {
			fs::path q;
			if (!fs::exists(fs::path("D:\\database\\"))) {
				q = fs::path("C:\\database\\" + ptr1->path + ".txt");
			}
			else {
				q = fs::path("D:\\database\\" + ptr1->path + ".txt");
			}
			fstream in(q, ios::in);
			if (!in) {
				cout << "The file could not be opened!" << endl;
				
				return false;
			}
			else {
				string line;
				while (getline(in, line)) {
					cout << line << endl;
				}
				in.close();
				
				return true;
			}
		}
		catch (const std::exception& e) {
			cout << "An error occurred: " << e.what() << endl;
			
			return false;
		}
	}
	bool delete1() {
		try {
			fs::path q;
			if (!fs::exists(fs::path("D:\\database\\"))) {
				q = fs::path("C:\\database\\" + ptr1->path + ".txt");
			}
			else {
				q = fs::path("D:\\database\\" + ptr1->path + ".txt");
			}
			if (fs::exists(q)) {
				fs::remove(q);
				
				return true;
			}
			else {
				cout << "The file does not exist!" << endl;
				
				return false;
			}
		}
		catch (const std::exception& e) {
			cout << "An error occurred: " << e.what() << endl;
			
			return false;
		}
	}
	bool renb() {
		try {
			fs::path q;
			fs::path p;
			if (!fs::exists(fs::path("D:\\database\\"))) {
				q = fs::path("C:\\database\\" + ptr1->path + ".bin");
			}
			else {
				q = fs::path("D:\\database\\" + ptr1->path + ".bin");
			}
			if (!fs::exists(fs::path("D:\\database\\"))) {
				p = fs::path("C:\\database\\" + ptr1->newpath + ".bin");
			}
			else {
				p = fs::path("D:\\database\\" + ptr1->newpath + ".bin");
			}
			if (fs::exists(q)) {
				fs::rename(q, p);

				return true;
			}
			else {
				cout << "The file does not exist!" << endl;
				return false;
			}
		}
		catch (const std::exception& e) {
			cout << "An error occurred: " << e.what() << endl;
			return false;
		}
	}
	
	bool sbin() {
	try {
		fs::path q;
		if (!fs::exists(fs::path("D:\\database\\"))) {
			q = fs::path("C:\\database\\" + ptr1->path + ".txt");
		}
		else {
			q = fs::path("D:\\database\\" + ptr1->path + ".txt");
		}
		fstream file(q, ios::out | ios::binary);
		if (!file) {
			cout << "The file could not be opened!" << endl;
			return false;
		}
		else {
			for (int i = 0; i < (ptr1->data).length(); i++) {
				char secret_byte = (ptr1->data)[i] ^ 0xAA; // 使用简单的异或加密
				file.write(&secret_byte, sizeof(secret_byte));
				file << endl;
			}
			file.close();
				
			return true;
		}
	}


	catch (const std::exception& e) {
		cout << "An error occurred: " << e.what() << endl;
		return false;
		}


	}

	bool rbin() {
		
		try {
			string output = "";
			fs::path q;
			if (!fs::exists(fs::path("D:\\database\\"))) {
				q = fs::path("C:\\database\\" + ptr1->path + ".txt");
			}
			else {
				q = fs::path("D:\\database\\" + ptr1->path + ".txt");
			}
			fstream infile(q, ios::in | ios::binary);
			if (!infile){
				cout << "The file could not be opened!" << endl;
				return false;
			}
			else {
				char encrypted_byte;
				while (infile.read(&encrypted_byte, sizeof(encrypted_byte))) {
					char original_byte = encrypted_byte ^ 0xAA; // 解密
					output += original_byte;
				}
				infile.close();
				cout << output << endl;
				
				return true;
			}
		}
		catch (const std::exception& e) {
			cout << "An error occurred: " << e.what() << endl;
			return false;
		}
	
	
	}
	bool abin() {
		
		try {
			fs::path q;
			if (!fs::exists(fs::path("D:\\database\\"))) {
				q = fs::path("C:\\database\\" + ptr1->path + ".txt");
			}
			else {
				q = fs::path("D:\\database\\" + ptr1->path + ".txt");
			}
			fstream file(q, ios::app | ios::binary);
			if (!file) {
				cout << "The file could not be opened!" << endl;
				return false;
			}
			else {
				for (int i = 0; i < (ptr1->data).length(); i++) {
					char secret_byte = (ptr1->data)[i] ^ 0xAA; // 使用简单的异或加密
					file.write(&secret_byte, sizeof(secret_byte));

				}
				file.close();

				return true;
			}
		}


		catch (const std::exception& e) {
			cout << "An error occurred: " << e.what() << endl;
			return false;
		}
	
	}
	bool dbin() {
		try {
			fs::path q;
			if (!fs::exists(fs::path("D:\\database\\"))) {
				q = fs::path("C:\\database\\" + ptr1->path + ".txt");
			}
			else {
				q = fs::path("D:\\database\\" + ptr1->path + ".txt");
			}
			if (fs::exists(q)) {
				fs::remove(q);

				return true;
			}
			else {
				cout << "The file does not exist!" << endl;

				return false;
			}
		}
		catch (const std::exception& e) {
			cout << "An error occurred: " << e.what() << endl;

			return false;
		}
	}
	bool listAll() {
	try {
		// 遍历 "D:\database" 目录中的所有条目
		fs::path q;
		if (!fs::exists(fs::path("D:\\database\\"))) {
			q = fs::path("C:\\database\\");
		}
		else {
			q = fs::path("D:\\database\\");
		}
		for (const auto& entry : fs::directory_iterator(q)) {

			// 检查当前条目是否是普通文件（不是文件夹）
			if (entry.is_regular_file()) {

				// 获取文件名并输出到控制台
				// entry.path().filename().string() 的作用：
				// - entry.path(): 获取完整路径
				// - .filename(): 提取文件名部分（去掉路径）
				// - .string(): 转换为字符串格式
				cout << entry.path().filename().string() << endl;
			}
		}
		return true;  // 遍历成功
	}
	catch (const std::exception& e) {
		// 如果出现错误（比如目录不存在），捕获异常并显示错误信息
		cout << "An error occurred: " << e.what() << endl;
		return false;  // 遍历失败
		}
	}
	void help() {
		cout << "This is a simple Multi-purpose tool application.\n"
			"0. write: Save content to a notebook file.(delete old)\n"
			"1. append: Save content to a notebook file(app to end)\n"
			"2. read: Read content from a notebook file.\n"
			"3. delete: Delete a notebook file.\n"
			"4. listAll: List all notebook files in the database directory.\n"
			"5. Binary encrypted write: Save content to a binary file with simple encryption.\n"
			"6. Binary encrypted read: Read content from a binary file with decryption.\n"
			"7. Binary encrypted append: Append content to a binary file with encryption.\n"
			"8. Binary encrypted delete: Delete a binary notebook file.\n"
			
			"9. rename: Rename a notebook file.\n"
			"10. Binary encrypted rename: Rename a binary notebook file.\n"
			"help: Display this help message.\n"
			"q. exit: Exit the application." << endl;
	
	}
};

























class media {
private:
	struct f2 {
		string name;
		sf::RenderWindow window;
		//sf::CircleShape circle;
		//文本显示需要的成员
		sf::Font font;
		sf::Text text;
		sf::Text itext;
		
		//按钮需要的成员
		sf::RectangleShape button;
		sf::Text buttonText;
		//输入框需要的成员
		sf::RectangleShape inputBox;
		sf::Text inputText;
		sf::String inputString;
		string savestr;

		bool isTyping;
	};
	std::unique_ptr<f2> ptr2;

public:
	save obj;
	void setpath(string n) {
		ptr2 = std::make_unique<f2>();
		ptr2->name = n;
	}
	void win() {
		try {

			ptr2->window.create(sf::VideoMode(1600, 900), ptr2->name);
			//初始化圆
			/*ptr2->circle.setRadius(50.f);//设置半径
			ptr2->circle.setFillColor(sf::Color::Red);//设置颜色
			ptr2->circle.setPosition(350, 250);//设置位置(居中)*/
			//初始化字体
			ptr2->window.setKeyRepeatEnabled(true);
			ptr2->font.loadFromFile("C:\\Windows\\Fonts\\simsun.ttc");
			if (ptr2->font.getInfo().family.empty()) {
				cout << "Error" << endl;
			}
			else {
				cout << "Home: " << ptr2->font.getInfo().family << endl;
			}
			//设置文本
			ptr2->text.setFont(ptr2->font);//加载字体
			ptr2->text.setString("Note\nFormat: Choice/filename|content.Example: mynote|Hello World");//文本内容

			ptr2->text.setCharacterSize(24);//设置字体大小(磅)
			ptr2->text.setFillColor(sf::Color::White);//设置字体颜色
			ptr2->text.setPosition(50, 45);//设置文本位置
			//功能介绍
			ptr2->itext.setFont(ptr2->font);
			ptr2->itext.setString("0. write: Save content to a notebook file.(delete old)\n"
								  "1. append: Save content to a notebook file(app to end)\n"
								  "2. delete: Delete a notebook file.\n"
								  "3. Binary encrypted write: Save content to a binary file with simple encryption.\n"
								  "4. Binary encrypted append: Append content to a binary file with encryption.\n"
								  "5. Binary encrypted delete: Delete a binary notebook file.\n"


			);

			ptr2->itext.setCharacterSize(24);
			ptr2->itext.setFillColor(sf::Color::White);
			ptr2->itext.setPosition(50, 550);
			//初始化按钮背景(矩形)
			ptr2->button.setSize(sf::Vector2f(200, 60));//设置按钮大小
			ptr2->button.setFillColor(sf::Color::Green);//设置按钮颜色
			ptr2->button.setPosition(50, 100);//设置按钮位置
			//初始化按钮文本
			ptr2->buttonText.setFont(ptr2->font);//加载字体
			ptr2->buttonText.setString("NO");//按钮文本内容

			ptr2->buttonText.setCharacterSize(24);//设置字体大小
			ptr2->buttonText.setFillColor(sf::Color::White);//设置字体颜色
			ptr2->buttonText.setPosition(50, 100);//设置按钮文本位置

			//输入框
			ptr2->inputBox.setSize(sf::Vector2f(500, 400));//设置输入框大小
			ptr2->inputBox.setFillColor(sf::Color::White);//设置输入框颜色
			ptr2->inputBox.setPosition(50, 150);//设置输入框位置
			ptr2->inputBox.setOutlineThickness(2);//设置边框厚度
			ptr2->inputBox.setOutlineColor(sf::Color::Blue);//设置边框颜色

			//输入框文本
			ptr2->inputText.setFont(ptr2->font);
			ptr2->inputText.setString("Enter...");

			ptr2->inputText.setCharacterSize(20);
			ptr2->inputText.setFillColor(sf::Color::Black);
			ptr2->inputText.setPosition(55, 155);

			ptr2->inputString = "";
			ptr2->isTyping = false;



		}
		catch (const std::exception& e) {
			cout << "An error occurred: " << e.what() << endl;
		}
	}
	void run() {
		try {
			if (!ptr2) { return; }

			while (ptr2->window.isOpen()) {
				sf::Event event;
				while (ptr2->window.pollEvent(event)) {
					if (event.type == sf::Event::Closed) {
						ptr2->window.close();

					}
					if (event.type == sf::Event::MouseButtonPressed
						) {
						int mouseX = event.mouseButton.x;
						int mouseY = event.mouseButton.y;

						// 检查鼠标点击是否在按钮范围内
						if (mouseX >= 50 && mouseX <= 250 &&
							mouseY >= 100 && mouseY <= 160) {
							ptr2->button.setFillColor(sf::Color::Red); // 更改按钮颜色
							cout << "Wow, F..." << endl;
						}

					}
					if (event.type == sf::Event::MouseButtonReleased) {
						ptr2->button.setFillColor(sf::Color::Green); // 恢复按钮颜色

					}
					//点击输入框
					if (event.type == sf::Event::MouseButtonPressed) {
						int MouseX = event.mouseButton.x;
						int MouseY = event.mouseButton.y;
						if (MouseX >= 50 && MouseX <= 550 &&
							MouseY >= 150 && MouseY <= 550) {
							ptr2->isTyping = true;
							ptr2->inputBox.setOutlineColor(sf::Color::Blue);
						}
						else {
							ptr2->isTyping = false;
							ptr2->inputBox.setOutlineColor(sf::Color::Black);
						}

					}
					//键盘输入
					if (event.type == sf::Event::TextEntered && ptr2->isTyping) {
						//回车键提交(ASCII 13)
						if (event.text.unicode == 13) {
							std::basic_string<sf::Uint8> utf8Data = ptr2->inputString.toUtf8();
							std::string utf8Str;
							utf8Str.reserve(utf8Data.size());

							for (sf::Uint8 byte : utf8Data) {
								utf8Str += static_cast<char>(byte);
							}
							cout << utf8Str << endl;
							
							// 调试输出，看看实际保存的内容
							/*cout << "原始保存内容: ";
							for (char c : ptr2->savestr) {
								printf("%02x ", (unsigned char)c);
							}
							cout << endl;
							cout << "文本内容: " << ptr2->savestr << endl;*/
							size_t ppl = utf8Str.find('/');
							string ch = "0";
							if (ppl != string::npos) {
								ch = utf8Str.substr(0, ppl);
								utf8Str = utf8Str.substr(ppl + 1);
							}

							// 查找 | 分隔符
							size_t pos = utf8Str.find('|');
							string filename = "test";
							string content = utf8Str;

							if (pos != string::npos) {
								filename = utf8Str.substr(0, pos);
								content = utf8Str.substr(pos + 1);
							}

							
							if (!content.empty()) {
								if (ch == "0") {
									obj.setdata(content, filename);
									obj.save2();
								}
								else if (ch == "1") {
									obj.setdata(content, filename);
									obj.save1();
									
								}
								
								else if (ch == "2") {
									obj.setdata("", filename);
									obj.delete1();
									
								}
								
								else if (ch == "3") {
									obj.setdata(content, filename);
									obj.sbin();
									
								}
								
								else if (ch == "4") {
									obj.setdata(content, filename);
									obj.abin();
									
								}
								else if (ch == "5") {
									obj.setdata("", filename);
									obj.dbin();
									
								}
								
								else {
									cout << "Invalid operation code. Use 0-7." << endl;
								}
								
								
								ptr2->savestr = "";

							}
							//cout << "Input submitted: " << ptr2->inputString.toAnsiString() << endl;
							ptr2->inputString = "";
							ptr2->inputText.setString("");//清空显示
						}
						else if (event.text.unicode == 8) {
							if (!ptr2->inputString.isEmpty()) {
								ptr2->inputString = ptr2->inputString.substring(0, ptr2->inputString.getSize() - 1);
							}
						}
						else {

							ptr2->inputString += event.text.unicode;


						}

						ptr2->inputText.setString(ptr2->inputString);
					}

				}
				ptr2->window.clear(sf::Color::Black);
				ptr2->window.draw(ptr2->text);
				ptr2->window.draw(ptr2->itext);
				ptr2->window.draw(ptr2->button);//绘制按钮背景
				ptr2->window.draw(ptr2->buttonText);//绘制按钮文本
				ptr2->window.draw(ptr2->inputBox);//绘制输入框
				ptr2->window.draw(ptr2->inputText);//绘制输入文本
				ptr2->window.display();

			}
		}

		catch (const std::exception& e) {
			cout << "An error occurred: " << e.what() << endl;
		}
	}
	

};




























int main()
{
	try {
		// 程序启动时检查并创建数据库目录（只执行一次）
		string basePath = "D:\\database";
		if (!fs::exists("D:\\")) {
			basePath = "C:\\database";
		}
		
		// 检查目录是否存在，不存在再创建
		if (!fs::exists(basePath)) {
			fs::create_directories(basePath);
			cout << "Database directory created: " << basePath << endl;
		}
		else {
			
			cout << "Database directory: " << basePath << endl;
		}
		
		
		SetConsoleOutputCP(65001);
		SetConsoleCP(65001);
		
		save obj;
		media sf;
		
		
		while (true) {
			cout << "Multi-purpose tool\n"
						"0. write\n1. append\n2. read\n3. delete\n4. listAll\n5. Binary encrypted write\n6. Binary encrypted read\n7. Binary encrypted append\n8. Binary encrypted delete\n9. rename\n10. Binary encrypted rename\nhelp. get help\nq. exit" << endl;
					string choice;
		
					cout << ">>> ";
					
					getline(cin, choice);
					
					
			if (choice == "0") {
				string data, name;
				cout << "Enter the name of the notebook(input exit to exit): ";
				getline(cin, name);
				if (name == "exit") {
					cout << "Operation cancelled." << endl;
					continue;
				}
				cout << "Enter the content to save(input exit to exit): ";
				getline(cin, data);
				if (data == "exit") {
									cout << "Operation cancelled." << endl;
									continue;
								}
				obj.setdata(data, name);
				
				if (obj.save2()) {
					cout << "Content appended successfully!" << endl;
					continue;
				}
				else {
					cout << "Failed to append content." << endl;
					continue;
				}
			}
			
			else if (choice == "1") {
				string data, name;
				cout << "Enter the name of the notebook(input exit to exit): ";
				getline(cin, name);
				if (name == "exit") {
					cout << "Operation cancelled." << endl;
					continue;
				}
				cout << "Enter the content to append(input exit to exit): ";
				getline(cin, data);
				if (data == "exit") {
					cout << "Operation cancelled." << endl;
					continue;
				}
				obj.setdata(data, name);
				
				if (obj.save1()) {
					cout << "Content saved successfully!" << endl;
					continue;
				}
				else {
					cout << "Failed to save content." << endl;
					continue;
				}
			}
			else if (choice == "2") {
				string name;
				cout << "Enter the name of the notebook to read(input exit to exit): ";
				getline(cin, name);
				if (name == "exit") {
					cout << "Operation cancelled." << endl;
					continue;
				}
				obj.setdata("", name);
				
				if (obj.read1()) {
					cout << "Content read successfully!" << endl;
					continue;
				}
				else {
					cout << "Failed to read content." << endl;
					continue;
				}
			}
			else if (choice == "3") {
				string name;
				cout << "Enter the name of the notebook to delete(input exit to exit): ";
				getline(cin, name);
				if (name == "exit") {
					cout << "Operation cancelled." << endl;
					continue;
				}
				obj.setdata("", name);
				
				if (obj.delete1()) {
					cout << "Notebook deleted successfully!" << endl;
					continue;
				}
				else {
					cout << "Failed to delete notebook." << endl;
					continue;
				}
			}
			else if (choice == "4") {
				if (obj.listAll()) {
					cout << "Listed all notebooks successfully!" << endl;
					continue;
				}
				else {
					cout << "Failed to list notebooks." << endl;
					continue;
				}
			}
			else if (choice == "5") {
				string data, name;
				cout << "Enter the name of the notebook(input exit to exit): ";
				getline(cin, name);
				if (name == "exit") {
					cout << "Operation cancelled." << endl;
					continue;
				}
				cout << "Enter the content to save(input exit to exit): ";
				getline(cin, data);
				if (data == "exit") {
									cout << "Operation cancelled." << endl;
									continue;
				}
				obj.setdata(data, name);
				
				if (obj.sbin()) {
					cout << "Content saved to binary file successfully!" << endl;
				}
				else {
					cout << "Failed to save content to binary file." << endl;
				}
			}
			else if (choice == "6") {
				string name;
				cout << "Enter the name of the notebook to read(input exit to exit): ";
				getline(cin, name);
				if (name == "exit") {
					cout << "Operation cancelled." << endl;
					continue;
				}
				obj.setdata("", name);
				
				if (obj.rbin()) {
					cout << "Content read from binary file successfully!" << endl;
				
				}
				else {
					cout << "Failed to read content from binary file." << endl;
				}
			}
			else if (choice == "7") {
				string data, name;
				cout << "Enter the name of the notebook(input exit to exit): ";
				getline(cin, name);
				if (name == "exit") {
					cout << "Operation cancelled." << endl;
					continue;
				}
				cout << "Enter the content to save(input exit to exit): ";
				getline(cin, data);
				if (data == "exit") {
									cout << "Operation cancelled." << endl;
									continue;
				}
				obj.setdata(data, name);
				
				if (obj.abin()) {
					cout << "Content saved to binary file successfully!" << endl;
				}
				else {
					cout << "Failed to save content to binary file." << endl;
				}
			}
			else if (choice == "8") {
				string name;
				cout << "Enter the name of the notebook to delete(input exit to exit): ";
				getline(cin, name);
				if (name == "exit") {
									cout << "Operation cancelled." << endl;
									continue;
				}
				obj.setdata("", name);
				
				if (obj.dbin()) {
					cout << "Notebook deleted successfully!" << endl;
					continue;
				}
				else {
					cout << "Failed to delete notebook." << endl;
					continue;
				}
			}
			else if (choice == "9") {
				string oname, nname;
				cout << "Enter the old name to rename(input exit to exit): " << endl;
				getline(cin, oname);
				if (oname == "exit") {
					cout << "Operation cancelled." << endl;
					continue;
				}
				cout << "Enter the new name(input exit to exit): " << endl;
				getline(cin, nname);
				if (nname == "exit") {
					cout << "Operation cancelled." << endl;
					continue;
				}
				else {

					obj.rename(oname, nname);
						
					
					if (!obj.rent()) {
						cout << "Rename failed." << endl;
					}
					else {
						cout << "Rename successful." << endl;
					}
				}
			}
			else if (choice == "10") {
				string oname, nname;
				cout << "Enter the old name to rename(input exit to exit): " << endl;
				getline(cin, oname);
				if (oname == "exit") {
					cout << "Operation cancelled." << endl;
					continue;
				}
				cout << "Enter the new name(input exit to exit): " << endl;
				getline(cin, nname);
				if (nname == "exit") {
					cout << "Operation cancelled." << endl;
					continue;
				}
				else {
					obj.rename(oname, nname);
					if (!obj.renb()) {
						cout << "Rename failed." << endl;
					}
					else {
						cout << "Rename successful." << endl;
					}
				}
			}
			else if (choice == "test") {
				sf.setpath("QA");
				sf.win();
				
				sf.run();
					
				
				
			}
			else if (choice == "help") {
				obj.help();
			}
			else if (choice == "q") {
				break;
			}
			else {
				cout << "Invalid choice. Please try again." << endl;
			}
			
	
	
	
		}
		/*cout << "Press Enter to exit...";
		cin.get();*/
	}
	catch (const std::exception& e) {
		cout << "An error occurred: " << e.what() << endl;
	}
	return 0;
}
// End of QA.cpp