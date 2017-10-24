#include "BrowserHistory.h"

//constuctor
BrowserHistory::BrowserHistory() {
   nav_iter = nav_hist.begin(); 
}

//deconstuctor
BrowserHistory::~BrowserHistory() {
    // TO BE COMPLETED
}

//creates a new website and adds it to nav_hist and history
void BrowserHistory::visitSite(Webpage newSite) {
    history.push_back(newSite); 

    nav_iter++;
    nav_hist.insert(nav_iter, newSite);
    nav_iter--;

    list<Webpage>::iterator it = nav_hist.end();
    it--; 
    while (it != nav_iter) {
        it--; 
        nav_hist.pop_back(); 
    }
}

//returns the URL
string BrowserHistory::getURL() {
    return nav_iter->getURL(); 
}

//returns nav size
size_t BrowserHistory::getNavSize() {
    return nav_hist.size(); 
}

//moves the iterator back
string BrowserHistory::back() {
    nav_iter--; 
    return nav_iter->getURL();
}

//moves the iterator foward
string BrowserHistory::forward() {
    nav_iter++;
    return nav_iter->getURL();
}

//Load information from a text file 
void BrowserHistory::readHistory(string filename) {
    ifstream myfile(filename);
    
        if (myfile.is_open()) {
            cout << "Successfully opened file " << filename << endl;
            string word;
            string url;
            time_t t;

            while (myfile >> word){
                if (word == "forward"){
                    forward();
                }
                else if (word == "back"){
                    back();
                }
                else if (word == "new")
                {
                    myfile >> url >> t; 
                    visitSite(Webpage(url, t));
                }
            }
            myfile.close();
        }
        else
            throw invalid_argument("Could not open file " + filename);
}

//prints all previous sites in the nav chain
void BrowserHistory::printBackSites() {
    list<Webpage>::iterator print_back = nav_hist.begin();

    while (print_back != nav_iter){
        cout << print_back->getURL() <<endl; 
        print_back++; 
    }
}

//Prints all forward sites in the nav chain
void BrowserHistory::printForwardSites() {
    list<Webpage>::iterator print_forward = nav_iter;

    while (print_forward != nav_hist.end()){
        cout << print_forward->getURL() <<endl;
        print_forward++; 
    }
}


//Prints out the full History 
void BrowserHistory::printFullHistory() {
    list<Webpage>:: iterator print_history = history.begin();

    while (print_history != history.end()){
        cout << print_history->getURL() <<endl; 
        print_history++;
    }
}
