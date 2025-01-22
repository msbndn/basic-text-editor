# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Папки
SRC_DIR = src
BUILD_DIR = build

# Исходные файлы
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Объектные файлы (Размещение в BUILD_DIR)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Исполняемый файл
TARGET = $(BUILD_DIR)/editor

# Правило по умолчанию
all: $(TARGET)

# Сборка исполняемого файла
$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Компиляция объектных файлов
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка временных файлов
clean:
	rm -rf $(BUILD_DIR)