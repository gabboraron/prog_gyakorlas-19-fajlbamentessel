#ifndef ENOR_H_INCLUDED
#define ENOR_H_INCLUDED
#include <fstream>
#include <vector>
#include <string>

using namespace std;

enum status{norm,abnorm};

struct vasarlo{
    string time;
    string id;
    vector<string> items;
};

class enor{
    public:
        enor(std::string&);
        enum enorerror{OpenError};
        void first();
        void next();
        //vetites current() const;
        bool end();

        /* filebairas */
        //Outfile(std::string fname="");
        void Write(const vasarlo &df);
        //~Outfile(){ f.close();}
        /* *** */

    private:
        std::ifstream x;
        //vetites dx;
        status sx;
        void read();

        /* keres arukod22 */
        bool voltarukod22;
        /* *** */

        /* keres minimum vasarlasok */
        bool elsovasarlo = true;
        int minOfItems;
        vasarlo minvasarlo;
        /* *** */

        /* filebairas */
        std::ofstream f;
        /* *** */
};


#endif // ENOR_H_INCLUDED
