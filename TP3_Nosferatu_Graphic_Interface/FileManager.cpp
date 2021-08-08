#include "FileManager.h"

bool FileManager::openFile(std::string fileName) {
    inputFile.open(fileName, std::ios::in);
    return (inputFile.is_open());
}

void FileManager::closeFile() {
    inputFile.close();
}

void FileManager::readFile() {

}
