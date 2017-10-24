#include "Webpage.h"

Webpage::Webpage() {
    url = "N/A";
    t_visited = 0; 
}

Webpage::Webpage(const string& webpageURL, const time_t& timeVisited) {
    url = webpageURL;
    t_visited = timeVisited;
}

string Webpage::getURL() {
    return url;
}

time_t Webpage::getTime() {
    return t_visited; 
}
