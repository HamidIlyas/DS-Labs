#include <iostream>
using namespace std;

class Publication
{
public:
    virtual void display() = 0;
};

class Book : public Publication
{
public:
    string title;
    string author;
    int pages;

    Book()
    {
        title = "";
        author = "";
        pages = 0;
    }

    Book(string t, string a, int p)
    {
        title = t;
        author = a;
        pages = p;
    }

    void display()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
    }
};

class Newspaper : public Publication
{
public:
    string name;
    string date;
    string edition;

    Newspaper()
    {
        name = "";
        date = "";
        edition = "";
    }

    Newspaper(string n, string d, string e)
    {
        name = n;
        date = d;
        edition = e;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Edition: " << edition << endl;
    }
};

class Library
{
public:
    Book books[10];
    Newspaper papers[10];
    int bc;
    int nc;

    Library()
    {
        bc = 0;
        nc = 0;
    }

    void addBook(Book b)
    {
        books[bc] = b;
        bc++;
    }

    void addNewspaper(Newspaper n)
    {
        papers[nc] = n;
        nc++;
    }

    void displayCollection()
    {
        cout << "Books: " << endl;
        for (int i = 0; i < bc; i++)
        {
            books[i].display();
            cout << endl;
        }

        cout << "Newspapper: " << endl;
        for (int i = 0; i < nc; i++)
        {
            papers[i].display();
            cout << endl;
        }
    }

    void sortBooksByPages()
    {
        for (int i = 0; i < bc - 1; i++)
        {
            for (int j = 0; j < bc - i - 1; j++)
            {
                if (books[j].pages > books[j + 1].pages)
                {
                    Book tmp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = tmp;
                }
            }
        }
    }

    void sortNewspapersByEdition()
    {
        for (int i = 0; i < nc - 1; i++)
        {
            for (int j = 0; j < nc - i - 1; j++)
            {
                if (papers[j].edition > papers[j + 1].edition)
                {
                    Newspaper tmp = papers[j];
                    papers[j] = papers[j + 1];
                    papers[j + 1] = tmp;
                }
            }
        }
    }

    Book* searchBookByTitle(string title)
    {
         int l = 0, h = bc - 1;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (books[mid].title == title)
            {
                return &books[mid];
            }
            else if (books[mid].title < title)
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
        return NULL;
    }

    Newspaper* searchNewspaperByName(string name)
    {
      int l = 0, h = nc - 1;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (papers[mid].name == name)
            {
                return &papers[mid];
            }
            else if (papers[mid].name < name)
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
        return NULL;
    }
};

int main() {
    // Create book objects
    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);

    // Create newspaper objects
    Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
    Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");

    // Create a library object
    Library library;

    // Add books and newspapers to the library
    library.addBook(book1);
    library.addBook(book2);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    // Display the entire collection
    cout << "Before Sorting:\n";
    library.displayCollection();

    // Sort books by pages and newspapers by edition
    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    cout << "\nAfter Sorting:\n";
    library.displayCollection();

    // Search for a book by title
    Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
    if (foundBook) {
        cout << "\nFound Book:\n";
        foundBook->display();
    }
    else {
        cout << "\nBook not found.\n";
    }

    // Search for a newspaper by name
    Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");
    if (foundNewspaper) {
        cout << "\nFound Newspaper:\n";
        foundNewspaper->display();
    }
    else {
        cout << "\nNewspaper not found.\n";
    }

    return 0;
}
