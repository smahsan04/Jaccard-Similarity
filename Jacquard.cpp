#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

// Function to calculate Jaccard similarity
double jacquard_similarity(string str1, int size1, string str2, int size2) {
	
	set<char>set1(str1.begin(),str1.end());
	set<char>set2(str2.begin(),str2.end());
	
	double similar_count = 0;
	
// Create a map to store the count of elements in set1	
	map <char, int> element_count;
	
// Increment the count for each element in set1
    for (char element : set1) 
	{
        element_count[element]++;
    }

// Check the count of each element in set2 and update the commonCount
    for (char element : set2) {
        if (element_count.find(element) != element_count.end() && element_count[element] > 0) {
            similar_count++;
            element_count[element]--;
        }
    }
    
    double unique_count = size1 + size2 - similar_count;
    
    int repeat = 0;
    
    for(int i = 0 ; i <= size1 ; i++)
    {
    	for(int j = i+1 ; j <=size1 ; j++)
    	{
    		if(str1[i] == str1[j])
    		repeat++;
		}
	}
	
	for(int i = 0 ; i <=size2 ; i++)
    {
    	for(int j = i+1 ; j <=size2 ; j++)
    	{
    		if(str2[i] == str2[j])
    		{
			    repeat++;
			}
		}
	}
	
	unique_count -= repeat;

    // Calculate Jaccard similarity
    double jacquardsimilarity = similar_count/unique_count;

    return jacquardsimilarity;
}

int main() {
    string data_set1 = {'w' , 'i' , 'l' , 'd' , 'f' , 'i' , 'r' , 'e'};
    int size1 = data_set1.size();
    
    string data_set2 = {'f' , 'i' , 'r' , 'e' , 'w' , 'o' , 'r' , 'k' , 's'};
    int size2 = data_set2.size();

    // Calculate Jaccard similarity
    double similarity = jacquard_similarity(data_set1, size1, data_set2, size2);

    // Print the result
    cout << "Jaccard Similarity: " << similarity << endl;
    return 0;
}
