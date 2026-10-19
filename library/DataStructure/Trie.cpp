#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <shuphy.hpp>
/* =========================================== */

// https://qiita.com/hibit/items/8001325a0591f4681473

struct Node{
    map<char, Node*> nxt; // 次の頂点のポインタ
    // その他、ノードに持たせたい情報を以下に書く
    int cnt = 0; // このノードを共有する文字列の数
};

struct Trie{
  private: 
    bool suffix; // trueにすると接尾辞モード 途中で変えられないようにprivateへ
  public:
    Node root; // 根ノード

    // コンストラクタ
    Trie() : suffix(false) {}
    Trie(bool suf_mode) : suffix(suf_mode) {}

    // 文字列の追加
    void insert(string s){
        Node* cur = &root;
        cur->cnt++; // 空文字列もカウント
        if(suffix) reverse(all(s));

        for(auto c : s){
            if(!(cur->nxt.count(c))){
                // 遷移先が存在しない場合新たに作成
                cur->nxt[c] = new Node(); // 新しいノードをつなげる
                // 新しいノードの情報を登録
                cur->nxt[c]->cnt++;
            } else {
                // 遷移先が既に存在する
                // 遷移先ノードの情報を更新
                cur->nxt[c]->cnt++;
            }
            cur = cur->nxt[c]; // 次のノードへ
        }
    }
    // 文字列の配列を一気に追加
    void insert(const vector<string>& S){
        for(auto &s : S){
            this->insert(s);
        }
    }

    // 文字列の検索 接頭辞が何文字一致するか返す
    int search(string s){
        Node* cur = &root;
        int ret = 0; // 一致した長さ
        if(suffix) reverse(all(s));

        for(auto c : s){
            if(cur->nxt.count(c)){
                // 遷移先がある
                ++ret;
                cur = cur->nxt[c];
            } else {
                // 遷移先がない
                break;
            }
        }
        return ret;
    }

    // 中身を出力 小さいサンプルでやること
    void debug(){
        if(!DEBUG) return;

        auto dfs = [&](auto& dfs, Node* cur, int depth) -> void {
            for(auto [c, to] : cur->nxt){
                for(int i = 0; i < depth; ++i){
                    cout << '_';
                }
                cout << c << el;
                dfs(dfs, to, depth+1);
            }
        };

        cout << "\033[34m";
        dfs(dfs, &root, 0);
        cout << "\033[m";
    }
};

/* =========================================== */

int main(){
    Trie tr; // 通常は接頭辞モード
    vector<string> S = {"apple", "api", "fire", "firework", "fight"};
    tr.insert(S);

    tr.debug();

    cout << tr.search("app") << el;
    cout << tr.search("happy") << el;
    cout << tr.search("fireman") << el;

    Trie rev(true); // 接尾辞モード
    vector<string> T = {"cry", "try", "code", "coder"};
    rev.insert(T);

    rev.debug();

    cout << rev.search("country") << el;
    cout << rev.search("happy") << el;
    cout << rev.search("october") << el;

    return 0;
}

/*
文字列のTrie木を作ります
基本は接頭辞からになります
宣言時、引数にtrueを与えると接尾辞からになります(すべての関数において、文字列はreverseせずにそのまま渡す)

接尾辞モードでreverseを使う影響でコピーコストが発生します
元の文字列がreverseされてもよいなら参照渡しも可能です

引数の文字列の長さをNとすると
insert: O(N)
search: O(N) くらい
どちらも実際はlogが付きます
*/
