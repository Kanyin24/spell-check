#include "trie_header.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    Trie Trie_tree;
    ifstream fin("corpus.txt");

    string cmd;
    string word;
    string prefix;
    while (cin >> cmd)
    {
        if(cmd == "load")
        {
            while(fin>>word)
            {
                Trie_tree.insertWord(word);
                //cout << word << endl;
                //do we ensure duplicate words aren't added in the insertWord function?
            }
            cout << "success" << endl;
        }
        if(cmd == "i")
        {
            cin >> word;
            //cout << cmd;
            //cout << word << endl;
            try{
                Trie_tree.checkIllegalInput(word);
                bool wordExists = Trie_tree.checkifWordExistsInTrie(word);
                if(wordExists == false)
                {
                    Trie_tree.insertWord(word);
                    cout << "success" << endl;
                }
                else
                {
                    cout << "failure" << endl;
                }
            }
            catch(illegal_exception)
            {
                cout << "illegal argument" << endl;
                //break;
            }
        }
        if(cmd == "c")
        {
            cin >> prefix;

            //need a try catch here as well
            try{
                Trie_tree.checkIllegalInput(prefix);
                bool isEmpty = Trie_tree.isEmpty();
                if(isEmpty == false)
                {
                    int count = Trie_tree.searchPrefix(prefix);

                    if(count == 0)
                    {
                        cout << "not found" << endl;
                    }
                    else
                    {
                        cout << "count is " << count << endl;
                    }
                }
                else
                {
                    cout << "not found" << endl;
                }
                
            }
            catch(illegal_exception)
            {
                cout << "illegal argument" << endl;
                //break;
            }
        }
        if(cmd == "e")
        {
            cin >> word;
            try{
                Trie_tree.checkIllegalInput(word);
                bool wordExist = Trie_tree.checkifWordExistsInTrie(word);
                //cout << wordExist << "checking if the word exists or not" << endl;
                if(Trie_tree.isEmpty() == false && wordExist == true) {
                    Trie_tree.eraseWord(word);
                    int numWords = Trie_tree.get_num_of_words() - 1;
                    Trie_tree.set_num_of_words(numWords);
                    cout << "success" << endl;
                }   
                else
                {
                    // bool check = Trie_tree.isEmpty();
                    // cout << check << " tells whether the trie is empty" << endl;
                    cout << "failure" << endl;
                }
            }
            catch(illegal_exception)
            {
                cout << "illegal argument" << endl;
                //break;
            }
            
        }
        if(cmd == "p")
        {
            //cout << Trie_tree.isEmpty() << " is it empty?" << endl;
            if(Trie_tree.isEmpty() == true)
            {
                
            }
            else
            {
                Trie_tree.printTrie(Trie_tree.get_p_root());
                cout << endl;
            }
            
        }
        if(cmd == "spellcheck")
        {
            cin >> word;

            bool firstLetterExists = Trie_tree.spellCheckFirstLetterExists(word);
            //cout << "does first letter exist: " << firstLetterExists << endl;

            if(firstLetterExists == false)
            {
                cout << endl;
            }
            else
            {
                bool wordInTrie = Trie_tree.spellCheckInTrie(word);
                //cout << " does the word in trire exist: " << wordInTrie << endl;
                if(wordInTrie == true)
                {
                    cout << "correct" << endl;
                }
                else
                {
                    cout << endl;
                }
                Trie_tree.Word.clear();
            }

            //first check if the first letter exists, if it doesn't don't output anything just do cout << endl;
            //else, if it does exist, check spellcheckintrie (if the word isn't in the tree, the function inside should call the spellcheck function)
                //this will do the recusive print of words with the same index

            //Trie_tree.spellCheckInTrie(word);
            //Trie_tree.spellCheckFirstLetterExists(word);
            //Trie_tree.spellCheck(word);
            //Trie_tree.printWord();
        }
        if(cmd == "empty")
        {
            //fix empty
            bool isEmpty = Trie_tree.isEmpty();
            if(isEmpty == true)
            {
                cout << "empty 1" << endl;
            }
            else 
            {
                cout << "empty 0" << endl;
            }
        }
        if(cmd == "clear")
        {   
            Trie_tree.deleteAllNodes(Trie_tree.get_p_root());
            Trie_tree.createEmptyRoot();
            Trie_tree.set_num_of_words(0);
            cout << "success" << endl;
            
        }
        if(cmd == "size")
        {
            bool isEmpty = Trie_tree.isEmpty();
            // if(isEmpty == true)
            // {
            //     cout << "number of words is 0" << endl;
            // }
            int numWords = Trie_tree.get_num_of_words();
            cout << "number of words is " << numWords << endl;
        }
        if(cmd == "exit")
        {
            break;
        }
    }
}