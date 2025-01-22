#ifndef TEXT_HISTORY
#define TEXT_HISTORY

#include <vector>
#include <string>

class TextHistory {
private:
    std::vector<std::vector<std::string>> history;
    const unsigned short int MAX_HISTORY_SIZE = 10;
    std::vector<std::string> initialText;

public:
    TextHistory(const std::vector<std::string>& text);
    void AddText(const std::vector<std::string>& text);
    void Undo(std::vector<std::string>& text);
    void SetInitialText(const std::vector<std::string>& text);
    void ClearHistory();  
};

#endif