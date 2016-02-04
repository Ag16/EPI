//integer roman numeral conversions
#include <iostream>
#include <string>
#include <vector>
#include <tr1/unordered_map>


using namespace std;
using namespace tr1;

bool isValidRoman(string s);
bool isValidException(char a, char b);
bool convertRomanToInt(string s, int &n);
bool convertIntToRoman(int n, string &s);
void appendRomanDigitReverse(int t,string digits, string &s);
void reverseString(string &s);

int main(){
	int choice;
	while(1){
		cout<<"1. Check validity of roman number \n2. Convert Roman to Integer\n3. Convert Integer to Roman\n4. Exit";
		cout<<endl<<"Enter choice : ";
		cin>>choice;
		int n;
		string s;
		switch(choice){
			case 1 : 
				cout<<"Enter the roman numeral : ";
				cin>>s;
				if(isValidRoman(s))
					cout<<"It is a valid Roman numeral"<<endl;
				else
					cout<<"It is not a valid Roman numeral in upper case"<<endl;
				cout<<endl<<endl;
				break;
			
			case 2:
				cout<<"Enter the roman numeral in uppercase : ";
				cin>>s;
				if(convertRomanToInt(s,n))
					cout<<n<<endl;
				else
					cout<<"It is not a valid Roman numeral in upper case"<<endl;
				cout<<endl<<endl;
				break;
			
			case 3:
				cout<<"Enter the integer : ";
				cin>>n;
				if(convertIntToRoman(n, s))
					cout<<s<<endl;
				else
					cout<<"Integer should be less thatn 3999!"<<endl;
				cout<<endl<<endl;
				break;
				
			case 4:
				cout<<endl;
				return 0;
				break;
			default:
				cout<<"Enter a valid choice"<<endl;
				cout<<endl<<endl;
		}
	}
	return 0;
}

void reverseString(string &s){
	char temp;
	for(int i=0, j = s.length()-1 ; i<j ; i++, j--){
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

void appendRomanDigitReverse(int t,string digits, string &s){
	if(t <= 0)
		;
	else if (t<= 3){
		for(int i=0 ; i<t ; i++)
			s.push_back(digits[0]);
	}
	else if(t == 4){
		s.push_back(digits[1]);
		s.push_back(digits[0]);
	}
	else if(t < 9){
		for(int i = 0 ; i < t-5 ; i++)
			s.push_back(digits[0]);
		s.push_back(digits[1]);
	}
	else{
		s.push_back(digits[2]);
		s.push_back(digits[0]);
	}
}

bool convertIntToRoman(int n, string &s){
	//the maximum number that can be converted is 3999
	if( n > 3999)
		return false;
	
	vector <string> digits;
	digits.push_back("IVX");
	digits.push_back("XLC");
	digits.push_back("CDM");
	digits.push_back("M");
	
	int t;
	for(int i=0 ; i < 4 ; i++){
		t = n % 10;
		n /= 10;
		appendRomanDigitReverse(t, digits[i], s);
	}
	reverseString(s);
	return true;
}

bool convertRomanToInt(string s, int &n){
	//check if the roman number is a valid one
	if(!isValidRoman(s))
		return false;
		
	//create an unordered map containing the values of individual roman digits
	unordered_map <char,int> m;
	m['I'] = 1;	
	m['V'] = 5;
	m['X'] = 10;	
	m['L'] = 50;
	m['C'] = 100;
	m['D'] = 500;	
	m['M'] = 1000;
	
	int l = s.size();
	//set n to be equal to the last digit ie the least significant digit of the roman numeral
	n = m[s[l-1]];
	
	//start the loop to iterate over the whole list and add numbers
	for(int i = l-2 ; i>= 0 ; i--){
		if(m[s[i]] < m[s[i+1]])
			n -= m[s[i]];
		else
			n += m[s[i]];
	}
	return true;
}

bool isValidException(char a, char b){
	if(a == 'I' && (b == 'V' || b == 'X'))
		return true;
	if(a == 'X' && (b == 'L' || b == 'C'))
		return true;
	if(a == 'C' && (b == 'D' || b == 'M'))
		return true;
	
	return false;
}

bool isValidRoman(string s){
	if(s.size() == 0)
		return false;

	unordered_map<char,int> m;
	m['I'] = 1;	
	m['V'] = 2;
	m['X'] = 3;
	m['L'] = 4;	
	m['C'] = 5;	
	m['D'] = 6;
	m['M'] = 7;
	int exceptionFlag = false;
	
	//check the first digit
	if(m.find(s[0]) == m.end())
		return false;
	
	//check the subsequent digits
	char max = *s.rbegin();

	for(string::reverse_iterator rit = s.rbegin() + 1 ; rit != s.rend() ; rit++){
		if(m.find(*rit) == m.end())
			return false;
		else{
			if(m[*rit] >= m[max]){
				max = *rit;
				//set exception flag to false
				exceptionFlag = false;
			}
			else{
				//an exception or invald input may arise
				//in either case, the exception flag already being set means that the present input is invalid
				if(exceptionFlag)
					return false;
				else{
					if(isValidException(*rit, *(rit-1)))
						exceptionFlag = true;
					else
						return false;
				}
			}
		}
	}
	return true;
}
