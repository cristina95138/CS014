//
//  Playlist.h
//  LinkedListLab
//
//  Created by Cristina Lawson on 3/31/19.
//  Copyright © 2019 Cristina Lawson. All rights reserved.
//

#ifndef Playlist_h
#define Playlist_h

#include <iostream>
using namespace std;

class PlaylistNode {
    
private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;

public:
    PlaylistNode();
    PlaylistNode(string, string, string, int);
    void InsertAfter(PlaylistNode*);
    void SetNext(PlaylistNode*);
    string GetID() const;
    string GetSongName() const;
    string GetArtistName() const;
    int GetSongLength() const;
    PlaylistNode* GetNext() const;
    void PrintPlaylistNode(PlaylistNode*) const;
};


#endif /* Playlist_h */
