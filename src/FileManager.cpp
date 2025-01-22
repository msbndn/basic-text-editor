#include "FileManager.h"

FileManager::FileManager(std::string filePath) {
    this->filePath = filePath;
}

std::string FileManager::get_file_path() const { return this->filePath; }

void FileManager::set_file_path(const std::string &filePath) { this->filePath = filePath; }

void FileManager::open_file(TextEditor *textEditor) { 
    const std::string initialFilepath = this->filePath;
    ChangeFilepath();

    std::ifstream fin(filePath, std::ios_base::in);
    
    if (!fin.is_open()) { 
        this->set_file_path(initialFilepath);
        return; 
    }

    textEditor->ClearText();

    std::string line;
    while (std::getline(fin, line)) {
        textEditor->AddLine(line);
    }

    textEditor->ClearHistory();

    fin.close(); 
}

void FileManager::save_file(const TextEditor *textEditor) { 
    if (this->filePath == "data\\unnamed.txt") { this->ChangeFilepath(); }
    
    std::ofstream fout(filePath, std::ios_base::out | std::ios_base::trunc);

    if(!fout.is_open()) { return; }

    for (const std::string& line : textEditor->get_text()) {
        fout << line << "\n";
    }

    fout.close();
}

void FileManager::save_to_file(const TextEditor *textEditor) { 
    this->ChangeFilepath();
    this->save_file(textEditor);
}

void FileManager::ChangeFilepath() {
    std::cout << "\nEnter file path: ";
    std::cin.ignore();
    std::getline(std::cin, filePath);
}