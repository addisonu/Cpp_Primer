#include <iostream>
#include <cstring>
#include <new>

int lastIndexOf(char *arr, char target);
void reverse(char *arr);
int replace(char *arr, char target, char replacementChar);
int findSubstring(char *arr, char substring[]);
bool isPalindrome(char *arr);
void changeCaps(char *arr, size_t size);

//change case for isPalindrome, lastIndexOf

int main()
{
	size_t szarr(6), szsbstr(4);
	
	char arr1[] = {'H', 'E', 'L', 'l', 'O', '\0'};
	char arr2[] = {'U', 'a', ' ', 'A', 'u', '\0'};
	char sbstr[] = {'e', 'l', 'L', '\0'};

	std::cout << "\nreverse(hello): " << std::endl;
	reverse(arr1);
	for(int i = 0; i < szarr; i++){
		std::cout << arr1[i];
	}
	std::cout << std::endl;
	
	std::cout << "\nisPalindrome(hello): " << std::endl << isPalindrome(arr1) << std::endl;
        std::cout << "\nisPalindrome(ua au): " << std::endl << isPalindrome(arr2) << std::endl;

	std::cout << "\nlastIndexOf(hello, 'l'): " << std::endl << "Unless the output is -1, the last index is " << lastIndexOf(arr1, 'h') << std::endl;
	
	std::cout << "\nreplace(olleh, 'h', 'u'): " << std::endl << "The number of replacements is " << replace(arr1, 'h', 'u') << std::endl;
	std::cout <<  "The new c-string is "; 	
	for(int i = 0; i < szarr; i++){
                std::cout << arr1[i];
        }
        std::cout << std::endl;

	reverse(arr1);
	std::cout << "\nfindSubstring(hello, ell): " << "\nIf the substring is found, it starts at index "  
	<< findSubstring(arr1, sbstr) << "\n" << std::endl;
	
	return 0;
}

void changeCaps(char *arr, size_t size)
{
	for(int i = 0; i < size - 1; i++){
		if((int) arr[i] < 91 && (int) arr[i] > 64){
			arr[i] = (int) arr[i] + 32;
		}
	}
}

int findSubstring(char *arr, char sbstr[])
{
	int index(-1), cnt(0); 
	unsigned szarr(6), szsbstr(4);
	
	changeCaps(arr, szarr);
	changeCaps(sbstr, szsbstr);
	
	for(int i = 0, u = 0; i < szarr - 1; i++){
		if(arr[i] == sbstr[u]){
			u++;
			cnt = 1;
			for(int m = i + 1; u < (szsbstr - 1) && m < (szarr - 1); m++, u++){
				if(arr[m] == sbstr[u]){
					cnt++;
				}
				else{
					if((m + szsbstr - 1) >= (szarr - 1)){
						i = szarr - 1;
					}
					u = 0;
					m = szarr - 1;
					cnt = 0;
				}
			}
		if(cnt == (szsbstr - 1)){
			index = i;
			i = szarr - 1;
		}
		}
	}
        return index;
}

int replace(char *arr, char target, char replace)
{
     	unsigned cnt(0);
        size_t size(6), place(0);

	changeCaps(arr, size);

        for(unsigned i = 0; i < size; i++){
                if(arr[i] == target){
                        cnt++;
                        arr[i] = replace;
                }
              }

        return cnt;

}

int lastIndexOf(char *arr, char target)
{
	unsigned cnt(0);
	size_t size(6), place(0);

	changeCaps(arr, size);

	for(unsigned i = 0; i < size; i++){
		if(arr[i] == target){
			cnt++;
			place = i;
		}
	} 
	
	return place;
}

void reverse(char *arr)
{
	size_t size(6);
	char *tmp = new char[size];

	changeCaps(arr, size);

	tmp[6] = '\0';
	for(int i = size - 2, u = 0; i >= 0; i--, u++){
		tmp[u] = arr[i];
	}
	strcpy(arr, tmp);

	delete [] tmp;
}

bool isPalindrome(char *arr)
{
	size_t size(6);
	char *tmp = new char[size];

	changeCaps(arr, size);

	tmp[6] = '\0';
        for(int i = size - 2, u = 0; i >= 0; i--, u++){
                tmp[u] = arr[i];
        }
	
	bool outcome(0);

	outcome = strcmp(arr, tmp);
	
	delete [] tmp;
	
	return !outcome;
}
