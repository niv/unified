return() # TODO Upgrade - Random segfaults

add_plugin(Profiler
   "Profiler.cpp"
   "Timing.cpp"
   "Targets/AIMasterUpdates.cpp"
   "Targets/MainLoop.cpp"
   "Targets/NetLayer.cpp"
   "Targets/NetMessages.cpp"
   "Targets/ObjectAIUpdates.cpp"
   "Targets/ObjectEventHandlers.cpp"
   "Targets/Pathing.cpp"
   "Targets/Scripts.cpp")