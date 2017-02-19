#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string s, char c) {
    vector<string> res;
    string tmp = "";

    for (int i = 0; i < s.size(); i++)
        if (s[i] == c)
        {
            res.push_back(tmp);
            tmp = "";
        }
        else
            tmp += s[i];

    if (tmp != "")
        res.push_back(tmp);

    return res;
}

int main (int argc, char* argv[]) {
	string str;
	ifstream file("test.txt");

	if (!file.is_open()) {
		 cout << "Failed to open requested file.\n"
             << "Please check your filename or file path.\n";
        exit(EXIT_FAILURE);
	}

	getline(file, str);
	vector<string> hao = split(str, ' ');
	for(vector<string>::iterator itr=hao.begin(); itr!=hao.end(); ++itr) {
		cout<< *itr <<endl;
	}
	cout<<str<<endl;

	while (file.good()) {
		getline(file, str);
		cout<<str<<endl;
	}
	return 0;
}