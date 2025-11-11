#pragma once

class AbstractInterp4Command {
public:
    virtual ~AbstractInterp4Command() = default;
    virtual const char* GetCmdName() const = 0;
    virtual bool Execute() = 0;
};
