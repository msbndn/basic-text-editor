#ifndef FILE_MANAGER
#define FILE_MANAGER

#include "TextEditor.h"
#include <fstream>

class FileManager {
private:
    std::string filePath;

public:
    FileManager(std::string filePath);
    std::string get_file_path() const;
    void set_file_path(const std::string &filePath);
    void open_file(TextEditor *textEditor);
    void save_file(const TextEditor *textEditor);
    void save_to_file(const TextEditor *textEditor);
    void ChangeFilepath();
};

#endif