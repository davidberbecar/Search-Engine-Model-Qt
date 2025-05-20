//
// Created by David Berbecar on 20.05.2025.
//

#ifndef SERVICE_H
#define SERVICE_H
#include <vector>

#include "Document.h"


class Service {
private:
    std::vector<Document> documents;
    void readFromFile();
public:
    Service();
    ~Service()=default;
    std::vector<Document> getDocuments();
    std::string bestMatch(std::string match);
};



#endif //SERVICE_H
