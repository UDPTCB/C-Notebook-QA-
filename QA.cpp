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
		cout << "This is a simple notebook application.\n"
			"0. write: Save content to a notebook file.(delete old)\n"
			"1. append: Save content to a notebook file(app to end)\n"
			"2. read: Read content from a notebook file.\n"
			"3. delete: Delete a notebook file.\n"
			"4. listAll: List all notebook files in the database directory.\n"
			"5. Binary encrypted write: Save content to a binary file with simple encryption.\n"
			"6. Binary encrypted read: Read content from a binary file with decryption.\n"
			"7. Binary encrypted append: Append content to a binary file with encryption.\n"
			"8. Binary encrypted delete: Delete a binary notebook file.\n"
			"help: Display this help message.\n"
			"q. exit: Exit the application." << endl;
	
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

		SetConsoleOutputCP(CP_UTF8);
		SetConsoleCP(CP_UTF8);
		save obj;

		
		
		while (true) {
			cout << "Notebook\n"
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