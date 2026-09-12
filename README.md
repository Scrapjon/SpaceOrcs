# Space Orcs

.vscode/tasks.json (template):
```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "type": "shell",
            "label": "CMake Build and Run - DEBUG",
            "command": "cmake --build --preset spaceorcs-gcc && .\\out\\build\\spaceorcs-gcc\\SpaceOrcs.exe",
            "options": {
                "cwd": "${workspaceFolder}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}
```