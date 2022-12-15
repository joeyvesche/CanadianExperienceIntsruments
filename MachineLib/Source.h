/**
 * @file Source.h
 * @author joeyv
 *
 *
 */

#ifndef CANADIANEXPERIENCE_SOURCE_H
#define CANADIANEXPERIENCE_SOURCE_H

#include <vector>
class Sink;

/**
 * The rotation driving class
 */
class Source {
private:
    /// A vector of sinks, driven by driver
    std::vector<Sink*> mSinks;

public:
    /// Copy constructor (disabled)
    Source(const Source&) = delete;

    /// Assignment operator (disabled)
    void operator=(const Source&) = delete;

    Source();
    ~Source();

    void AddSink(Sink* sink);

    void SetRotation(double rotation);

};

#endif //CANADIANEXPERIENCE_SOURCE_H
