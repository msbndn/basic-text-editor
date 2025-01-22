#include "TextEditor.h"
#include "FileManager.h"

int main() {
    TextEditor *textEditor = new TextEditor;
    FileManager *fileManager = new FileManager{"data\\unnamed.txt"};

    while (true) {
        system("cls");
        std::cout << "Simple Text Editor!\n\n"
                << '<' << fileManager->get_file_path() << '>' << "\n\n"
                << "1. Display text\n"
                << "2. Add line\n"
                << "3. Remove line\n"
                << "4. Find substring\n"
                << "5. Undo\n"
                << "6. Open file(...)\n"
                << "7. Save file\n"
                << "8. Save to file(...)\n"
                << "0. Exit\n\n"
                << ">Choose the option: ";

        short int option;
        std::cin >> option;
        
        if (option == 1) { 
            textEditor->DisplayText(); 
            system("pause");
        } 
        else if (option == 2) { 
            std::cout << "> Enter line: ";
            std::string line;
            std::cin.ignore();
            std::getline(std::cin, line);

            textEditor->AddLine(line); 
        } 
        else if (option == 3) { 
            std::cout << ">Enter line number: ";
            unsigned int lineNumber;
            std::cin >> lineNumber;

            textEditor->RemoveLine(lineNumber); 
        } 
        else if (option == 4) { 
            std::cout << ">Enter substring: ";
            std::string searchText;
            std::cin.ignore();
            std::getline(std::cin, searchText);

            textEditor->FindSubstring(searchText); 
            system("pause");
        } 
        else if (option == 5) { textEditor->Undo();} 
        else if (option == 6) { fileManager->open_file(textEditor);} 
        else if (option == 7) { fileManager->save_file(textEditor); } 
        else if (option == 8) { fileManager->save_to_file(textEditor); } 
        else if (option == 0) { break; } 
    }

    delete(textEditor);
    delete(fileManager);

    return 0;
}