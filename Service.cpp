//
// Created by David Berbecar on 20.05.2025.
//

#include "Service.h"
#include<fstream>
#include<sstream>


Service::Service() {
    this->readFromFile();
}

std::vector<std::string> tokenize(std::string line, char delimiter) {
    std::stringstream ss(line);
    std::string token;
    std::vector<std::string> tokens;
    while (std::getline(ss,token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void Service::readFromFile() {
    std::ifstream file("documents.txt");
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    std::string line;

    while (std::getline(file,line)) {
        std::vector<std::string> tokens = tokenize(line, '|');
        this->documents.push_back(Document(tokens[0],tokens[1],tokens[2]));
    }
}

std::vector<Document> Service::getDocuments() {
    std::vector<Document> documents = this->documents;
    sort(documents.begin(),documents.end(),[](Document a, Document b){return a.getName() < b.getName();});
    return documents;
}

std::string Service::bestMatch(std::string match) {
    std::string result;
    double similarity=-999999999.9999;
    double max_sim=-99999.9999;
    for (auto document : documents) {
        if (document.getName().find(match)!=std::string::npos) {
            similarity=(double)match.length()/document.getName().length();
            if (similarity>max_sim) {
                max_sim=similarity;
                result=document.getName();
            }
        }
    }
    return result;
}