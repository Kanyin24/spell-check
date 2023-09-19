#ifndef HEAD
#include <iostream>
#include <vector>

class Node
{
    public:
        Node();
        ~Node();

        //getters
        bool get_endofWord();
        bool endOfWord_; //make endofWord a private variable and use getters and setters
        //Node* get

        Node* childrenPointers_[26];
        Node* ParentofNode = nullptr;
    private:
        
        
};

class Trie
{
    public:
        Trie();
        ~Trie();
        void insertWord(std::string addword);
        void checkIllegalInput(std::string word);
        int indexofLetter(char letter);
        void doesWordExist(bool wordExists);
        bool returndoesWordExist();
        void printTrie(Node* node);
        int searchPrefix(std::string prefix);
        void countWord(Node* node);
        bool isEmpty();
        void storeLettersinWord(char ascii_letter);
        void printWord();
        void eraseWord(std::string word);
        //void clearTrie(); //delete this after you finish the deleteAllNodes function
        bool hasChildren(Node* node);
        bool spellCheckInTrie(std::string word);
        void spellCheck(Node* node);
        bool spellCheckFirstLetterExists(std::string word);
        bool checkifWordExistsInTrie(std::string word);
        void deleteAllNodes(Node* node);
        void createEmptyRoot();
        //have like a check first letter (if it exists in the tree) function 
        
        
        std::vector <char> Word; //need to make this private later
        std::vector <char> Prefix;
        bool wordExist_; // should make this a private variable later
        int count_num_ = 0;
        int children_num_ = 0;

        //getters
        Node* get_p_root();
        int get_num_of_words();

        //setters
        void set_num_of_words(int num_words);

    private:
        Node *p_root_;
        Node *p_traverse_;
        int num_of_words_ = 0;
        
};

class illegal_exception{};

#endif