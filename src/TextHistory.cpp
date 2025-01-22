#include "TextHistory.h"

TextHistory::TextHistory(const std::vector<std::string>& text) {
    this->SetInitialText(text);
}

void TextHistory::AddText(const std::vector<std::string>& text) {
    if (this->history.size() >= this->MAX_HISTORY_SIZE) {
        this->SetInitialText(this->history[0]);
        this->history.erase(this->history.begin());
    }

    this->history.push_back(text);
}

void TextHistory::Undo(std::vector<std::string>& text) {
    if (this->history.size() == 0) {
        return;
    } else if (this->history.size() == 1) {
        this->history.pop_back();
        text = this->initialText;
    } else {
        this->history.pop_back();
        text = this->history[this->history.size() - 1];
    }
}

void TextHistory::SetInitialText(const std::vector<std::string>& text) {
    this->initialText = text;
}

void TextHistory::ClearHistory() {
    this->history.clear();
}