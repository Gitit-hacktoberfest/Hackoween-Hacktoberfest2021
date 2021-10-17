// Link:https://leetcode.com/problems/flood-fill/

/* Problem statment:

An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from
the pixel image[sr][sc].To perform a flood fill, consider the starting pixel, plus any pixels connected 
4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally
to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.

Return the modified image after performing the flood fill.*/

// Recusrive solution


// Here we will call the function 4 times for r+1 , r-1 , c+1 , c-1 to cover all four directions
// if our value is equal to old color we will change it to new color if not then we will return 
// if our old color and new color becomes same then also we will return no need to make any changes


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void changeColor(vector<vector<int>> &image,int row,int col,int newColor,int oldColor)
    {   
        // base conditions 
        
        if ( row>=image.size() || col >= image[0].size()|| row <0 || col <0 || image[row][col]!= oldColor || newColor == oldColor)
            return;
        
            image[row][col] = newColor; 
        
        changeColor(image,row+1,col,newColor,oldColor);  
        changeColor(image,row,col+1,newColor,oldColor);  
        changeColor(image,row-1,col,newColor,oldColor); 
        changeColor(image,row,col-1,newColor,oldColor);
    }
        
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
         
        int oldColor = image[sr][sc]; // store the value of old color
        
         changeColor(image,sr,sc,newColor,oldColor); 
        
         return image;
    }
};