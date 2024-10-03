#include <iostream>
#include <vector>

using namespace std;

void dfs(int r, int c, vector<vector<int>>& image, int color, int oldColor) {
    int m = image.size();
    int n = image[0].size();

    image[r][c] = color;

    int row[] = {-1, 0, 1, 0};
    int col[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        int rnew = r + row[i];
        int cnew = c + col[i];

        if (rnew >= 0 && rnew < m && cnew >= 0 && cnew < n && image[rnew][cnew] == oldColor) {
            dfs(rnew, cnew, image, color, oldColor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int m = image.size();
    int n = image[0].size();
    int oldColor = image[sr][sc];

    if (oldColor != color) {
        dfs(sr, sc, image, color, oldColor);
    }

    return image;
}

int main() {
    // Hardcoded input: image (2D grid) and starting point with new color
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    
    int sr = 1; // Starting row
    int sc = 1; // Starting column
    int newColor = 2; // New color to fill

    vector<vector<int>> result = floodFill(image, sr, sc, newColor);

    // Output the modified image
    cout << "Flood filled image: " << endl;
    for (const auto& row : result) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}
