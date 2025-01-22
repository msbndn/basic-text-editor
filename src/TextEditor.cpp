#include "TextEditor.h"

void TextEditor::set_text(const std::vector<std::string> &text) { 
    this->text = text;
}

std::vector<std::string> TextEditor::get_text() const { 
    return text; 
}

void TextEditor::DisplayText() const {
    system("cls");

    unsigned short int lineCount = 0;
    for (const std::string &line : this->text) {
        std::cout << ++lineCount << "|" << line << "\n";
    }
    std::cout << std::endl;
}

void TextEditor::AddLine(const std::string &line) {
    this->text.push_back(line);
    history.AddText(this->text);
}

void TextEditor::RemoveLine(const unsigned int &lineNumber) {
    if (this->text.empty()) { return; }
    if (lineNumber > this->text.size()) { return; }
    
    unsigned int lineCount = 0;
    for (auto line = this->text.begin(); line != this->text.end(); line++, lineCount++) {
        if (lineNumber - 1 == lineCount) {
            text.erase(line);
            
            break;
        }
    }
    history.AddText(this->text);
}

void TextEditor::FindSubstring(const std::string& searchText) {
    if (this->text.empty()) { return; }

    int countMatchesSubstring = 0;
    std::vector<int> lineNumbers;

    int lineCount = 0;
    for (const std::string &line : text) {
        ++lineCount;

        if (line.find(searchText) != std::string::npos) {
            for (size_t i = 0; i < line.size() - (searchText.size() - 1); i++) {
                if (line[i] == searchText[0]) {
                    if (line.substr(i, searchText.size()) == searchText) {
                        ++countMatchesSubstring;
                        i += searchText.size() - 1;
                    }
                }
            }
            lineNumbers.push_back(lineCount);
        }
    }

    std::cout << "Matches: " << countMatchesSubstring << "\n"
                << "Lines: ";

    for (const int &num : lineNumbers) {
        std::cout << num << " ";
    }

    std::cout << std::endl;
}

void TextEditor::Undo() {        
    history.Undo(this->text);
}

void TextEditor::ClearText() {
    this->text.clear();
}

void TextEditor::ClearHistory() {
    this->history.ClearHistory();
    this->history.SetInitialText(this->text);
}