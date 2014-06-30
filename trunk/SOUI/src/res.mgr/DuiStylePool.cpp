#include "duistd.h"
#include "res.mgr/DuiStylePool.h"

namespace SOUI
{

    // Get style object from pool by class name
    BOOL DuiStylePool::GetStyle(LPCWSTR lpszName, DuiStyle& style)
    {
        if(!HasKey(lpszName)) return FALSE;
        style=GetKeyObject(lpszName);
        return TRUE;
    }

    // Load style-pool from xml tree
    BOOL DuiStylePool::Init(pugi::xml_node xmlStyleRoot)
    {
        DUIASSERT(xmlStyleRoot);

        if (wcscmp(xmlStyleRoot.name(), L"style") != 0)
        {
            DUIASSERT(FALSE);
            return FALSE;
        }

        LPCWSTR lpszClassName = NULL;

        for (pugi::xml_node xmlChild=xmlStyleRoot.child(L"class"); xmlChild; xmlChild=xmlChild.next_sibling(L"class"))
        {
            lpszClassName = xmlChild.attribute(L"name").value();
            if (!lpszClassName)
                continue;

            GetKeyObject(lpszClassName).Load(xmlChild);
        }
        return TRUE;
    }
}//end of namespace SOUI
