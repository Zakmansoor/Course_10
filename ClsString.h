#pragma once
#include<iostream>
#include<string>
#include <vector>
using namespace std;
class ClsString
{
public:
    string _Value;
    ClsString(string Value)
    {
        this->_Value = Value;
    }
    static string substring(ClsString str)
    {
        return str._Value;
    }
    string Concat(string Value1,string Value2)
    {  
        return Value1 + Value2;
    }
     bool IsUpperCase(char value) {
        return value < 'a'?true : false;
    }   
     bool IsLowerCase(char value) {
        return value <= 'z'&&value >= 'a'? true : false;
    }   
    bool IsUpperCasetoAllWords()
    {
        bool letter;
        for (int i = 0; i < _Value.length();i++)
        {
            if (IsUpperCase(_Value[i]))
                letter = true;
            else
                return false;
        }
        return true;
    }
    bool IsLowerCasetoAllWords()
    {
        bool letter;
        for (int i = 0; i < _Value.length();i++)
        {
            if (IsLowerCase(_Value[i]))
                letter = true;
            else
                return false;
        }
        return true;
    }
    char toUpperCase(char value)
    {
        if (IsLowerCase(value))
            return value - 32;
        return value;
    }
    char toLowerCase(char & value)
    {
        if (value >= 'A' && value <= 'Z')
            return value+32;
        return value;
    }
    string UpperfirstofEachWords()
    {
        bool IsfirstLetter = true;
        for (int i = 0; i < _Value.length(); i++)
        {
            if (_Value[i] !=' ' && IsfirstLetter)
            {
                _Value[i] = toUpperCase(_Value[i]);
            }
            IsfirstLetter = _Value[i] == ' ' ? true : false;
        }
        return _Value;
    }
   static string LowerfirstofEachWords(ClsString cls)
    {
       return cls._Value;

    }
    string LowerfirstofEachWords()
    {
        string value = LowerfirstofEachWords(*this);
        bool IsfirstLetter = true;
        for (int i = 0; i < value.length(); i++)
        {
            if (value[i] !=' ' && IsfirstLetter)
            {
                value[i] = toLowerCase(value[i]);
            }
            IsfirstLetter = value[i] == ' ' ? true : false;
        }
        _Value = value;
        return _Value;
    }
    char InvertLetterCase(char& value)
    {
        if (IsUpperCase(value)) {
            return toLowerCase(value);
        }
        if (IsLowerCase(value)) {
            return toUpperCase(value);
        }
    }
   
   static string InvertAllLetterCase(ClsString str)
    {
       return str._Value;
    }

    void InvertAllLetterCase()
    {
        string value = _Value;
        for (int i = 0; i < _Value.length(); i++)
        {
            value[i] = InvertLetterCase(value[i]);
        }

        _Value = value;
    }
    vector<string> SplitString(string Value ,string delimeter)
    {
        vector<string> strValue;
        string str="";
        short pos = 0;
        while ((pos=Value.find(delimeter))!=string::npos) {
            str = Value.substr(0, pos);
            if (str != "")
            {
                strValue.push_back(str);
            }
            Value.erase(0, pos+ delimeter.length());
        }
        if (str != "")
        {
            strValue.push_back(Value);
        }
        return strValue;
    }
    short CountWord(string word, string delim)
    {
        short pos = 0;
        short count = 0;
        string str = "";
        while ((pos = word.find(delim)) != string::npos) {
            str = word.substr(0, pos);
            if (str != "")
            {
                count++;
            }
            word.erase(0, pos + delim.length());
        }
        if (str != "")
        {
            count++;
        }
        return count;
    }

   static string Substr(ClsString cslstring)
    {
       return cslstring._Value;
    }
    string Substr(int strat, int end)
    {
        string strsub = "";
        string strsubpoint = "";
        strsub = Substr(*this);
        for (int i = strat; i < end; i++)
        {
            strsubpoint = strsubpoint+ strsub[i];
        }
        return strsubpoint;
    }
    string Erase(int strat, int end)
    {
        string strsub = "";
        string strsubpoint = "";
        strsub = _Value;
      

            for (int j = 0; j < strsub.length(); j++)
            {

                if (j>=end || j< strat)
                {
                    strsubpoint = strsubpoint + strsub[j];
                }

            }
        
        _Value = strsubpoint;
        return strsubpoint;
    }

    void Append(string value)
    {
        _Value += value;
    }
    void Swap(string & Num1, string& Num2)
    {
        string temp ="";
        temp = Num1;
        Num1 = Num2;
        Num2 = temp; 
    }
    string ConvertToLineSting(vector<string> vctr)
    {
        string Line = "";

        for (string& s : vctr)
        {
            Line = Line+ s;
        }
        return Line;
    }
    string ToLowerAllStrnig(string& Value)
    {
        for (int i = 0; i < Value.length(); i++)
        {
            Value[i] = toLowerCase(Value[i]);
        }
        return
            Value;
    }
   
    string ReplaceWords(string wordfind, string wordreplace, string delimeter = " ")
    {
        short pos = 0;
        vector<string> strVetor;
        string word="";
        while ((pos = _Value.find(delimeter)) != std::string::npos) {
            word = _Value.substr(0, pos);
            if (word != "")
            {
                if (ToLowerAllStrnig(word) == ToLowerAllStrnig(wordfind))
                {
                    word = wordreplace;

                }
                else if (word == wordfind)
                {
                    word = wordreplace;

                }

                strVetor.push_back(word);
            }
            _Value.erase(0, pos + delimeter.length());


        };
        if (ToLowerAllStrnig(_Value) == ToLowerAllStrnig(wordfind))
        {
            _Value = wordreplace;

        }
        else if (_Value == wordfind)
        {
            _Value = wordreplace;

        }
            strVetor.push_back(_Value);
        string linstring  = "";
        linstring = ConvertToLineSting(strVetor);
       return linstring;

        
    }
    string ReplaceWrordInStringBuildInFunction(string st, string searchWord, string replaceWord)
        {
        	short pos = st.find(searchWord);
        	while (pos != std::string::npos)
        	{
        		st = st.replace(pos, searchWord.length(), replaceWord);
        		pos = st.find(searchWord);
        
        	}
        	return st;
        }
    string JoinString(vector<string>& vectrword, string delim)
    {
        string word = "";


        for (string & wordvct:vectrword)
        {
            word = word + wordvct + delim;
        }



        return word.substr(0, word.length() - delim.length());
    }

        // ReplaceWrordInString The best method
        string ReplaceWrordInString(string st, string replacementWord, string toreplace, bool MatchCase)
        {
        	vector<string> wordsplit = SplitString(st, " ");
        	for (string& s : wordsplit)
        	{
        		if (MatchCase)
        		{
        			if (s == replacementWord)
        				s = toreplace;
        		}
        		else {
        			if ((s) == ToLowerAllStrnig(replacementWord))
        				s = toreplace;
        		}
        	}
            _Value= JoinString(wordsplit, " ");
        	return JoinString(wordsplit, " ");
        }
        string TrimLeft(string Value)
        {
            for (int i = 0; i < Value.length(); i++)
            {
                
                if (_Value[i] != ' ')
                {
                        return Value.substr(i, _Value.length());
                    }
                }

            
        }
        string TrimRight(string Value)
        {
            for (int i = Value.length()-1; i >=0 ; --i)
            {
                
                if (Value[i] != ' ')
                {
                        return Value.substr(0, i);
                    }
                }

            
        }
        string Trim(string Value)
        {
            return TrimRight(TrimLeft(Value));
        }
        bool puncation(char value)
        {

            string list = "/+)(*&^%$#@!{'/";
            for (int i=0; i < list.length(); i++)
            {
                if (value == list[i])
                {
                    return true;
                }
            }
            return false;
     }
        string RemovePuncation(string Value)
        {
            string word="";
            for (int i=0; i < Value.length(); i++)
            {
                if (!puncation(Value[i]))
                {
                    word = word + Value[i];

                }
                    
            }
            return word;
        }
        string JoinChar(vector<char> Name)
        {
        
        	string st = "";
        	for (char& v : Name)
        	{
        		st = st + v;
        
        	}
        	return st.substr(0, st.length());
        }
        short CountSmallLetter_Case(string st)
        {
            short Counter = 0;
            for (int i = 0; i < st.length(); i++)
            {
                if (IsLowerCase(st[i]))
                {
                    ++Counter;
                }
            }
            return Counter;
        }
        short CountCapitalLetterCase(string st)
        {
            short Counter = 0;
            for (int i = 0; i < st.length(); i++)
            {
                if (IsUpperCase(st[i]))
                {
                    ++Counter;
                }
            }
            return Counter;
        }
        short CountSpecificLetter(char Letter)
        {
            short count = 0;
            for(int i=0; i< _Value.length(); i++)
            {
               if(Letter== _Value[i])
               {
                count++;
               }
            }
            return count;
        }
        void RevarseString()
        {
            string revstring = "";
            for (int i = _Value.length() - 1; i >= 0; i--)
            {
                revstring = revstring + _Value[i];
            }
            _Value = revstring;
            
        }


};

