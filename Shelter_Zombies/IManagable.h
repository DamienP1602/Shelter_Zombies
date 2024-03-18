#pragma once

template<typename ID>
class IManagable
{
protected:
    bool toRemove;
    ID id;

public:
    void SetID(const ID& _id)
    {
        id = _id;
    }
    void SetToRemove(const bool _status)
    {
        toRemove = _status;
    }
    ID GetID() const
    {
        return id;
    }
    bool IsToRemove() const
    {
        return toRemove;
    }

public:
    IManagable(const ID& _id)
    {
        id = _id;
        toRemove = false;
    }

private:
    virtual void Register() = 0;
};