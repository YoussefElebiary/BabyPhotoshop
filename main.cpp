#include <iostream>
#include "Image_Class.h"

using namespace std;

bool isValidFile(string);
void invert_image(string);

int main() {
    string file_name;
    int choice;
    //Welcome menu
    cout << "Welcome to the BabyPhotoShop program\n" << "This program allows you to apply filters to images\n\n";
    //Program loop
    while (true) {
        //Getting the file name
        cout << "Enter the file name and its extension (PNG/JPG/BMP/TGA): ";
        getline(cin, file_name);
        //Handling invalid filenames
        while (!isValidFile(file_name)) {
            cout << "Enter the file name and its extension (PNG/JPG/BMP/TGA): ";
            getline(cin, file_name);
        }
        //Getting which filter to apply to the image
        cout << "\nSelect which filter to apply\n";
        cout << "1) Grayscale Conversion\n2) Black and White\n3) Invert Image\n4) Exit";
        cout << "Choice: ";
        cin >> choice;
        //Handling invalid input
        while (cin.fail() || !(1 <= choice && choice <= 4)) {
            cout << "\nInvalid Input\n";
            cout << "\nSelect which filter to apply\n";
            cout << "1) Grayscale Conversion\n2) Black and White\n3) Invert Image\n4) Exit";
            cout << "Choice: ";
            cin >> choice;
        }
        //Applying the filters as entered
        if (choice == 1) {
            cout << "Under Development\n";
        } else if (choice == 2) {
            cout << "Under Development\n";
        } else if (choice == 3) {
            invert_image(file_name);
        } else if (choice == 4) {
            cout << "Exiting...\n" << "Thank you for using our program\n";
            break;
        }
    }

    return 0;
}


bool isValidFile(string file_name) {
    try {
        Image image(file_name);
        return true;
    } catch (exception& e) {
        return false;
    }
}

void invert_image(string file_name) {
    Image image(file_name);
    int w = image.width, h = image.height, save_type;
    string new_name;
    //Loading message
    cout << "Inverting the image...\n";
    //Looping over each pixel
    for (int i = 0; i < w; ++i) {           //Width
        for (int j = 0; j < h; ++j) {       //Height
            for (int k = 0; k < 3; ++k) {   //Channels
                image(i, j, k) = 255 - image(i, j, k);
            }
        }
    }
    //Success message
    cout << "Inverted Successfully\n\n";
    //Save type
    cout << "How do you want to save the image?\n";
    cout << "1) Replace the old image\n2) Save as a new image\nChoice: ";
    cin >> save_type;
    //Handling invalid input
    while (cin.fail() || !(1 <= save_type && save_type <= 2)) {
        cout << "Invalid Input\n";
        cout << "How do you want to save the image?\n";
        cout << "1) Replace the old image\n2) Save as a new image\nChoice: ";
        cin >> save_type;
    }
    //Saving the image according to the input
    if (save_type == 1) {
        image.saveImage(file_name);
        cout << "Saved Successfully\n";
    } else if (save_type == 2) {
        cout << "Enter the new image's name and format: ";
        cin.ignore();
        getline(cin, new_name);
        //Attempting to save the image
        while (true) {
            try {
                image.saveImage(new_name);
                cout << "Saved Successfully\n";
                break;
            } catch (exception &e) {
                cout << e.what() << '\n';
                cout << "Enter the new image's name and format: ";
                getline(cin, new_name);
            }
        }
    }
}