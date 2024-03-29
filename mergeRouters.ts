export declare type RouterInfo = {
    component: string;
    path: string;
    label?: string;
    paramCheck?: boolean;
    param?: string;
    canActivate?: string;
    canDeactivate?: string;
    children?: RouterInfo[];
    isDefault?: boolean;
   };

export declare type RouterArray = {
    fullpath: string, path: string, component: string, parentPath: string, newpath?: string
}
const blockRouters = {
    "routers": [
       {
    "path": "",
    "component": "AppComponent",
    "isDefault": false,
    "children": [
           {
    "path": "router",
    "component": "RouterComponent",
    "param": "",
    "canActivate": "",
    "canDeactivate": "",
    "isDefault": false,
    "children": [
        {
            "path": "router3",
            "component": "Router3Component",
            "param": "",
            "canActivate": "",
            "canDeactivate": "",
            "isDefault": false,
            "children": [
                {
                    "path": "router4",
                    "component": "Router4Component",
                    "param": "",
                    "canActivate": "",
                    "canDeactivate": "",
                    "isDefault": false,
                    "children": []
                },
                {
                    "path": "router5",
                    "component": "Router5Component",
                    "param": "",
                    "canActivate": "",
                    "canDeactivate": "",
                    "isDefault": false,
                    "children": []
                },
                {
                    "path": "router6",
                    "component": "Router6Component",
                    "param": "",
                    "canActivate": "",
                    "canDeactivate": "",
                    "isDefault": false,
                    "children": []
                }

            ]
            }
    ]
           }
         ]
       }
     ],
    "guards": []
};

const projectRouters = {
    "routers": [
       {
        "path": "",
        "component": "AppComponent",
        "isDefault": false,
        "children": [
            {
                "path": "router",
                "component": "RouterComponent",
                "param": "",
                "canActivate": "",
                "canDeactivate": "",
                "isDefault": false,
                "children": [
                    {
                    "path": "router3",
                    "component": "Router3Component",
                    "param": "",
                    "canActivate": "",
                    "canDeactivate": "",
                    "isDefault": false,
                    "children": [
                        {
                            "path": "router4",
                            "component": "Router4Component",
                            "param": "",
                            "canActivate": "",
                            "canDeactivate": "",
                            "isDefault": false,
                            "children": []
                        },
                        {
                            "path": "router4",
                            "component": "Router5Component",
                            "param": "",
                            "canActivate": "",
                            "canDeactivate": "",
                            "isDefault": false,
                            "children": []
                        }
                    ]
                    }
                ]
            },
            {
            "path": "router2",
            "component": "Router2Component",
            "param": "",
            "canActivate": "",
            "canDeactivate": "",
            "isDefault": false,
            "children": []
            },
            {
            "path": "router-home",
            "component": "Router-home-Component",
            "param": "",
            "canActivate": "",
            "canDeactivate": "",
            "isDefault": false,
            "children": [
                {"path": "router-home-child",
            "component": "Router-home-child-Component",
            "param": "",
            "canActivate": "",
            "canDeactivate": "",
            "isDefault": false,}
            ]
            }
        ]
        }
    ],
    "guards": []
};


function flattenRouters(routers: RouterInfo, parentPath: string, routersArray: RouterArray[], index?, searchPath?) {
    if (!searchPath) {
        searchPath = [];
        searchPath.push(0);
    } else {
        searchPath.push(index);
    }
    const temp = {
        fullpath: routers.path === '' ? parentPath : `${parentPath}/${routers.path}`, 
        path: routers.path, 
        component: routers.component,
        parentPath: parentPath,
        searchPath: searchPath};
    routersArray.push(temp);
    routers['searchPath'] = searchPath;
    if (routers.children) {
        routers.children.forEach((child, index) => flattenRouters(child, temp.fullpath, routersArray, index, searchPath.slice(0)));
    }
}
let projectRoutersArray = [];
let conflictedArray: any;
flattenRouters(projectRouters.routers[0], '', projectRoutersArray);
conflictedArray = findConflictedArray();
let conflictedRoutersArray = projectRoutersArray.filter(value => 
    conflictedArray.indexOf(value.searchPath.join(',')) > -1 );
console.log(conflictedRoutersArray)

function findConflictedArray(): any[] {
    return projectRoutersArray
    .filter(value => projectRoutersArray.filter((value2 => value2.fullpath === value.fullpath)).length > 1)
    .map(value => value.searchPath.join(','))
}
