//
//  Playlist.cpp
//  LinkedListLab
//
//  Created by Cristina Lawson on 3/31/19.
//  Copyright © 2019 Cristina Lawson. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

#include "Playlist.h"

PlaylistNode::PlaylistNode() : uniqueID("none"), songName("none"), artistName("none"), songLength(0), nextNodePtr(nullptr) {}

PlaylistNode::PlaylistNode(string uniqueID, string songName, string artistName, int songLength) : uniqueID(uniqueID), songName(songName), artistName(artistName), songLength(songLength), nextNodePtr(nullptr) {}

void PlaylistNode::InsertAfter(PlaylistNode* data) {
    PlaylistNode* temp = nullptr;
    temp = nextNodePtr;
    nextNodePtr = data;
    data->SetNext(temp);
}

void PlaylistNode::SetNext(PlaylistNode* next) {
    nextNodePtr = next;
}

string PlaylistNode::GetID() const {
    return uniqueID;
}

string PlaylistNode::GetSongName() const {
    return songName;
}

string PlaylistNode::GetArtistName() const {
    return artistName;
}

int PlaylistNode::GetSongLength() const {
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext() const {
    return nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode(PlaylistNode* nextData) const {
    cout << "Unique ID: " << nextData->GetID() << endl
         << "Song Name: " << nextData->GetSongName() << endl
         << "Artist Name: " << nextData->GetArtistName() << endl
         << "Song Length (in seconds): " << nextData->GetSongLength() << endl << endl;
}

