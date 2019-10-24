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
                            "path": "router5",
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
const projectRoutersArray:any = [];
const blockRoutersArray: any = [];

flattenRouters(projectRouters.routers[0], '', projectRoutersArray);
flattenRouters(blockRouters.routers[0], '', blockRoutersArray, []);

const conflictedRouters = showConflicted(projectRoutersArray, blockRoutersArray);

conflictedRouters.forEach((conflictedRouter) => {
    conflictedRouter['newpath'] = conflictedRouter.path + '1';
    return conflictedRouter;
    }
);
handleConflicted(conflictedRouters, blockRouters.routers[0]);
console.dir(JSON.stringify(blockRouters));

function flattenRouters(routers: RouterInfo, parentPath: string, routersArray: RouterArray[], index?, searchPath?) {
    if (!searchPath) {
        searchPath = [];
        searchPath.push('root');
    } else {
        searchPath.push(index);
    }
    const temp = {
        fullpath: routers.path === '' ? parentPath : `${parentPath}/${routers.path}`, 
        path: routers.path, 
        component: routers.component,
        parentPath: parentPath,
        searchPath: searchPath.slice(0)};
    routersArray.push(temp);
    if (routers.children) {
        routers.children.forEach((child, index) => flattenRouters(child, temp.fullpath, routersArray, index, searchPath.slice(0)));
    }
}

function showConflicted(projectRoutersArray: RouterArray[], blockRoutersArray: RouterArray[]) {
    const conflictedRouters: RouterArray[] = [];
    projectRoutersArray.forEach(projectRouter => 
        blockRoutersArray.forEach((blockRouter) => {
            if (blockRouter.fullpath === projectRouter.fullpath && blockRouter.component !== 'AppComponent') {
                conflictedRouters.push(blockRouter);
            }
        })
    );
    return conflictedRouters;
}

function handleConflicted(conflictedRouters: RouterArray[], blockRouters: RouterInfo) {
    conflictedRouters.forEach((conflictedRouter) => {
        renameBlockRouters(conflictedRouter, 0, blockRouters);
    });
}

function renameBlockRouters(conflictResolvedRouter: any, i: number, routers: RouterInfo) {
    const searchPath = conflictResolvedRouter.searchPath;
    if (searchPath.length - 1 === i ) {
        routers.path = conflictResolvedRouter.newpath;
    } else {
        if (routers.children) {
            i = i + 1;
            const index = searchPath[i];
            const child = routers.children[index];
            renameBlockRouters(conflictResolvedRouter, i,  child);
        }
    }
}