/*//////////////////////////////////////////////////////////////////
////       SKIRT -- an advanced radiative transfer code         ////
////       © Astronomical Observatory, Ghent University         ////
///////////////////////////////////////////////////////////////// */

#ifndef TEXTOUTFILE_HPP
#define TEXTOUTFILE_HPP

#include <fstream>
#include <QString>
#include <QVector>
#include "Array.hpp"
#include "SimulationItem.hpp"
class Log;

////////////////////////////////////////////////////////////////////

/** This class represents a writable text file that can be initizialized by providing a filename to
    its constructor. Text is written per line, by calling the writeLine() function. The file is
    automatically closed when the object is destructed. In a multiprocessing environment, only the
    root process will be allowed to write to the specified file; calls to writeLine() performed by
    other processes will have no effect. */
class TextOutFile
{
    //=============== Construction - Destruction  ==================

public:
    /** The constructor of the TextOutFile class. As an argument, it takes the filename (a QString
        instance). If the process that invokes it is the root, the output stream for the file is
        initialized. On other processes, this output stream remains uninitialized (and is never used). */
    TextOutFile(const SimulationItem* item, QString filename, QString description, bool overwrite = true);

    /** The destructor of the TextOutFile class. On the root process, the file will be automatically
        closed. */
    ~TextOutFile();

    //====================== Other functions =======================

public:
    /** This function is used to write a certain string to the file as a new line. If the calling
        process is not the root, this function will have no effect. */
    void writeLine(QString line);

    /** This function .. */
    void addColumn(QString description, char format = 'e', int precision = 6);

    /** This function .. */
    void writeRow(QVector<double> values, QString delimiter = " ");

    //======================== Data Members ========================

private:
    Log* _log;
    QString _filepath;
    std::ofstream _out;  // the output stream
    int _ncolumns;
    QVector<char> _formats;
    QVector<int> _precisions;
};

////////////////////////////////////////////////////////////////////

#endif // TEXTOUTFILE_HPP
