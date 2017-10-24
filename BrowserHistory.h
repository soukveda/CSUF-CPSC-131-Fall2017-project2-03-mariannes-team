#pragma once

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <stdexcept>
#include "Webpage.h"
using namespace std;

class BrowserHistory {
public:
    BrowserHistory();
    ~BrowserHistory();

    void visitSite(Webpage newSite);
    string back();
    string forward();

    void readHistory(string filename);

    string getURL();
    size_t getNavSize();

    void printBackSites();
    void printForwardSites();
    void printFullHistory();

private:
    list<Webpage> history; 
    list<Webpage> nav_hist;
    list<Webpage>::iterator nav_iter; 
};
