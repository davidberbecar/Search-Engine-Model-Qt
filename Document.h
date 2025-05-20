//
// Created by David Berbecar on 20.05.2025.
//

#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <string>


class Document {
private:
    std::string name;
    std::string keywords;
    std::string content;
public:
    Document(std::string name, std::string keywords, std::string content);
    ~Document()=default;
    std::string getName(){return name;};
    std::string getKeywords(){return keywords;};
    std::string getContent(){return content;};
    std::string toString(){return name+"\t"+keywords;};
};



#endif //DOCUMENT_H
