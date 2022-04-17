> 125% : )

## GET NEXT LINE

This project scope is to code a function that reads content from a file descriptor `fd` and returns the first matching line (chars followed by an `\n`).

There's a definition BUFFER_SIZE that stablishes the amount of characters we can gather per read call. The game is to handle cases in which you did read a content and for example it includes to line, for next call you need to return that line you've read. To do so we use an static variable and thus allocating and deallocating content from that variable since it has a program scope: )

