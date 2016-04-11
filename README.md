Uriparser
=========

Uriparser is a tool that downloads and parses a problem from URI Online Judge.
It creates a file for each input and output sample. It also comes with a script
that compiles, runs and tests your solution with the sample I/O.

Warning
-------

It is a bit buggy. It is still under development!

Install
-------

To install the current version, create a directory for your solutions
(say, ~/uri/)

    mkdir ~/uri

Insert the *parser* directory in it (not its files) and enter it.

    cp -r location/to/parser ~/uri/
    cd ~/uri/parser/

Compile *geraio.cpp*.

    make geraio

If you do not use *vim* as you code editor, consider editing the last line of
*parser.sh*.

Also, add the following to your *~/.bashrc* file:

    function uriparser {
        cd ~/uri/
        source ./parser/parser.sh $1
    }

Source your *~/.bashrc* file (or just close the terminal and open another one).

Usage
-----

From any directory, run

    uriparser <problemID>

This will create the directory ~/uri/*name*ID, where *name* is the first string
in the problem's title and ID is the problemID. It will also automatically open
your text editor so you can code your solution. To test it, run

    ./testa.sh

It will compile your solution and test it with the sample I/O.

Please notice that the parser is still buggy so the sample I/O will not be
parser correctly for some problems. It will correctly parse, for instance,
problem 1922
