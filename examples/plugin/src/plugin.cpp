#include <dbg.h>
#include <engine/iserverplugin.h>

#define PMsg(msg, ...) Msg("[Plugin] " msg "\n", __VA_ARGS__)

class Plugin : public IServerPluginCallbacks {
public:
  Plugin() {}
  ~Plugin() {}

  bool Load(CreateInterfaceFn interface_factory,
    CreateInterfaceFn game_server_factory) override {
    PMsg("Load");

    return true;
  }

  void Unload(void) override {
    PMsg("Unload");
  }

  void Pause(void) override {
    PMsg("Pause");
  }

  void UnPause(void) override {
    PMsg("UnPause");
  }

  const char* GetPluginDescription(void) override {
    return "Plugin";
  }

  void LevelInit(char const* map_name) override {
    PMsg("LevelInit: %s", map_name);
  }

  void ServerActivate(edict_t* edict_list, int edict_count,
    int client_max) override {
    PMsg("ServerActivate: edict_count=%d client_max=%d", edict_count, client_max);
  }

  void GameFrame(bool simulating) override {
  }

  void LevelShutdown(void) override {
    PMsg("LevelShutdown");
  }

  void ClientActive(edict_t* entity) override {
  }

  void ClientFullyConnect(edict_t* entity) override {
  }

  void ClientDisconnect(edict_t* entity) override {
  }

  void ClientPutInServer(edict_t* entity, char const* player_name) override {
  }

  void SetCommandClient(int index) override {
  }

  void ClientSettingsChanged(edict_t* entity) override {
  }

  PLUGIN_RESULT ClientConnect(bool* allow_connect, edict_t* entity,
    const char* name, const char* address,
    char* reject, int n_reject) override {
    return PLUGIN_CONTINUE;
  }

  PLUGIN_RESULT ClientCommand(edict_t* entity, const CCommand& args) override {
    return PLUGIN_CONTINUE;
  }

  PLUGIN_RESULT NetworkIDValidated(const char* username,
    const char* network_id) override {
    return PLUGIN_CONTINUE;
  }

  void OnQueryCvarValueFinished(QueryCvarCookie_t cookie,
    edict_t* player_entity,
    EQueryCvarValueStatus status,
    const char* cvar_name,
    const char* cvar_value) override {
  }

  void OnEdictAllocated(edict_t* edict) override {
  }

  void OnEdictFreed(const edict_t* edict) override {
  }
};

Plugin plugin{};
EXPOSE_SINGLE_INTERFACE_GLOBALVAR(Plugin, IServerPluginCallbacks, INTERFACEVERSION_ISERVERPLUGINCALLBACKS, plugin);
