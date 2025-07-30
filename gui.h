#ifndef GUI
#define GUI

#include "synth.h"
#include "raylib.h"
#include "imgui-node-editor/imgui_node_editor.h"
#include "rlImGui.h"

namespace ed = ax::NodeEditor;
using namespace ax::NodeEditor;

#ifndef WINDOW_WIDTH
    #define WINDOW_WIDTH (1920)
#endif

#ifndef WINDOW_HEIGHT
    #define WINDOW_HEIGHT (1080)
#endif

#ifndef ID_OFFSET
    #define ID_OFFSET (100)
#endif


class NodeView
{
private:
    AudioEngine* audioEngine;
    ax::NodeEditor::EditorContext* context;
    const char* title;
    bool showCreateWindow = false;
    char nodePrompt[128] = "";
    
public:
    NodeView(const char* title, AudioEngine* engine);
    ~NodeView();

    void Init();
    void Run();
    void DrawNodeGraph();
    void DrawCreatorWindow();
    void DrawNodeInspector();
    void Dispose();
};







#endif