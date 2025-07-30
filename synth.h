#ifndef SYNTH
#define SYNTH


#include <stdio.h>
#include <fstream>
#include <functional>
#include <string>
#include "portaudio.h"
//#include "portaudio/include/portaudio.h"
#include "json.hpp"
#include "nodes.h"
#include "nodes_rotary_encoder.h"

using namespace std;
using json = nlohmann::json;



#ifndef NUM_SECONDS 
    #define NUM_SECONDS   (5)
#endif
#ifndef SAMPLE_RATE 
    #define SAMPLE_RATE   (44100)
#endif
#ifndef FRAMES_PER_BUFFER
    #define FRAMES_PER_BUFFER  (64)
#endif

class NodeCreator;


class AudioEngine
{
private:
    PaStream* stream;
    PaStreamParameters outputParameters;
    PaStreamParameters inputParameters;
    // StreamData streamData;
    // LowPass<4> filter;
    // std::vector<Wave*> audioFiles;
    NodeGraph graph;
    vector<NodeCreator> creators;
    
public:
    AudioEngine();
    ~AudioEngine();

    void Start();
    void Dispose();
    void LoadAudioFile(char* path);
    void AddCreators();
    void LoadNodes();
    void Save();

    NodeGraph* GetGraph() { return &graph; }
    vector<NodeCreator>* GetNodeCreators() { return &creators; }

    // StreamData* getStreamData() {
    //    return &streamData;
    // }

};

int streamCallback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void *userData);


class NodeCreator
{
private:
    const char* name;
    std::function<void(NodeGraph*, json)> creator;
    
public:
    NodeCreator(const char* name, function<void(NodeGraph*, json)> graph);
    ~NodeCreator();
    const char* GetName() {return name;}
    void CreateNode(NodeGraph* graph, json json) { creator(graph, json); }
};



#endif