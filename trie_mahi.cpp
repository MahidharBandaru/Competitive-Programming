const int MaxN = 500500;
int sz = 0;
int next1[30][MaxN];
int end[MaxN];
bool created[MaxN];

    void addWord(string s) {
        int v = 0;
 
    for (int i = 0; i < s.size(); ++i) {
        int c = s[i] - 'a';
        if (!created[next1[c][v]]) {
            next1[c][v] = ++sz;
            created[sz] = true;
        }
        v = next1[c][v];
    }
        
    }

    bool search(string tmp) {
        
        int v = 0;
    int l=tmp.size();
    for (int i = 0; i < tmp.size(); ++i) {
        int c = tmp[i] - 'a';
        {if (!created[next1[c][v]])
            return false;
        v = next1[c][v];}
    }
    return true;
    }
