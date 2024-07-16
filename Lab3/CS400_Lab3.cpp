// CS400_Lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"PlayList.h"
#include <iostream>
#include <string>
using namespace std;


struct Song {
	string title;
	string artist;
	// pointer to the next song in the playlist. This forms the link between songs in the linked list
	Song* next;

	// default constructor that initializes title and artist, sets the pointer to nullptr
	// indicating that the new song does not point to any other song yet
	Song(string t, string a) : title(t), artist(a), next(nullptr) {}
};


class PlayList
{
private:
	// A pointer to the first song in the playlist
	Song* head;
public:
	// Initializes the head pointer to nullptr, meaning the playlist is initially empty
	PlayList() : head(nullptr) {}

	void addSong(string title, string artist) {
		// Creates a new song object with the given title and artist
		Song* newSong = new Song(title, artist);
		// Checks if the playlist is empty, if true sets head to the new song
		if (!head) {
			head = newSong;
		}
		// otherwise, iterates through the linked list to find the last song
		else {
			Song* temp = head;
			while (temp->next) {
				temp = temp->next;
			}
			temp->next = newSong;
		}
	}

	void removeSong(string title) {
		// Checks if the playlist is empty
		if (!head) return;

		// Checks if the song to be removed is the first song. If true, sets head
		// to the next song and deletes the current first song
		if (head->title == title) {
			Song* temp = head;
			head = head->next;
			delete temp;
			return;
		}

		// If the song to be removed is not the first song, iterates througn the
		// linked list to find the song with the matching title
		Song* temp = head;
		while (temp->next && temp->next->title != title) {
			temp = temp->next;
		}

		// If the song is found, adjust the pointers to bypass the song to be
		// removed and deletes the song
		if (temp->next) {
			Song* songToRemove = temp->next;
			temp->next = songToRemove->next;
			delete songToRemove;
		}
	}
	
	void displayPlaylist() const {
		// Iterates through the linked list starting from head
		Song* temp = head;
		// for each song, prints the title and aritst
		// Then moves to the next song until the end is reached
		while (temp) {
			cout << "Title: " << temp->title << ", Artist: " << temp->artist << endl;
			temp = temp->next;
		}
		cout << endl;
	}
};




int main()
{
	PlayList myPlaylist;

	myPlaylist.addSong("Song 1", "Artist 1");
	myPlaylist.addSong("Song 2", "Artist 2");
	myPlaylist.addSong("Song 3", "Artist 3");
	myPlaylist.addSong("Song 4", "Artist 4");

	myPlaylist.displayPlaylist();

	myPlaylist.removeSong("Song 2");

	myPlaylist.displayPlaylist();
}
