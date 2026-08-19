void visitRooms(int key, int** rooms, int roomsSize, int* roomsColSize, int* visitedRooms){
	fprintf(stderr, ">>> Entering visitRooms(key=%d,rooms=%p,roomsSize=%d,roomsColSize=%p,visitedRooms=%p)\n", key, rooms, roomsSize, roomsColSize, visitedRooms);
    if (visitedRooms[key] == 1){
        return;
    }

    visitedRooms[key] = 1;
    for (int i = 0; i < roomsColSize[key]; i++){
        visitRooms(rooms[key][i], rooms, roomsSize, roomsColSize, visitedRooms);
    }
	fprintf(stderr, "<<< Exiting visitRooms(key=%d,rooms=%p,roomsSize=%d,roomsColSize=%p,visitedRooms=%p)\n", key, rooms, roomsSize, roomsColSize, visitedRooms);
}

// Depth-first search
// Runtime: O(n)
// Space: O(n)
bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize){
	fprintf(stderr, ">>> Entering canVisitAllRooms(rooms=%p,roomsSize=%d,roomsColSize=%p)\n", rooms, roomsSize, roomsColSize);
    int* visitedRooms = calloc(roomsSize, sizeof(int));
    visitRooms(0, rooms, roomsSize, roomsColSize, visitedRooms);

    int visitedRoomsNumber = 0;
    for (int i = 0; i < roomsSize; i++){
        if (visitedRooms[i] == 1){
            visitedRoomsNumber++;
        }
    }

	fprintf(stderr, "<<< Exiting canVisitAllRooms(rooms=%p,roomsSize=%d,roomsColSize=%p)\n", rooms, roomsSize, roomsColSize);
    return visitedRoomsNumber == roomsSize;
}
