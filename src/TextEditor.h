#ifndef TEXT_EDITOR
#define TEXT_EDITOR

#include "TextHistory.h"
#include <iostream>

class TextEditor {
private:
    std::vector<std::string> text;
    TextHistory history{this->text};

public:
    void set_text(const std::vector<std::string> &text);
    std::vector<std::string> get_text() const;
    
    void DisplayText() const;
    void AddLine(const std::string& line);
    void RemoveLine(const unsigned int& lineNumber);
    void FindSubstring(const std::string& searchText);
    void Undo();
    void ClearText();
    void ClearHistory();
};

#endif