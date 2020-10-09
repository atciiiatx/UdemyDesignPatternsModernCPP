#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct Journal
{
    std::string _title;
    std::vector<std::string> _entries;

    Journal(const std::string &title) : _title(title) {}

    void AddEntry(const std::string &entry)
    {
        const int count = _entries.size();
        _entries.push_back(std::to_string(count) + ": " + entry);
    }
};

struct PersistenceManager
{
    static void Save(const Journal &journal, const std::string &fileName)
    {
        std::ofstream ofs(fileName);
        for (const auto &e : journal._entries)
        {
            ofs << e << std::endl;
        }
    }
};

int main()
{
    Journal journal("My Diary");
    journal.AddEntry("I ate a bug.");
    journal.AddEntry("I went swimmming.");

    PersistenceManager pm;
    pm.Save(journal, "journal.txt");
    return 0;
}