---

# Planning

## Repository
  - Dynamic README generation. Either append build journal to README automatically or fully generate a README file on build from sources.
  - Some sort of configuration -> template resolution model (mustache?).

## App Structure:
  - Use CMakeLists to build with cmake

## Code Paradigm:
  - Follow OOP for increased performance. Use FP wherever in modular components where the performance lost is sufficiently mitigated or absent altogether.

## Code Features:
  - Monads
    - optional monad
    - error handling monad
  - Expose interface for python scripting

## App
  - logger
    - togglable
    - can set levels
    - can output to multiple streams
    - can log objects
    - log function name
    - log line number
  - network
    - serve data to client
    - allow client to get data from database

## Game Objects:
  - game
  - player

## Notes:
  - use 'auto' to shorten for loops?

---

# Milestones

  - name: hello world [X]

  - name: CMakeLists file [X]

  - name: build logger            [X]
      basic logging               [X]
      configurable levels         [X]
      multi-stream output         [X]
      custom log levels           []
      logging to database         []
      log to db (postprocess)     []
      object logging              []
      log file names              []
      log line numbers            []
      log function names          []
      live level configuration    []

  - name: read/write to sql []

  - name: togglable maintenance mode    []
  - name: trigger a maintenance cycle   []
      interval processing               []
        transfer logs to database       []
        garbage collection?             []
        
  - name: scheduled maintenance cycles  []

---


=== old

- use venvs

- demo "hello world"  [X]

- demo importing python modules
  - requires CPython

- demo using ctypes to interface with c code
