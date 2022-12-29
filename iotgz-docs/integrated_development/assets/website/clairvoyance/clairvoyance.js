(function () {
    /* 
        参数：hideColorBar: （Bool）是否隐藏颜色工具，默认false
             hideInput:  （Bool）是否隐藏输入工具，默认false
             hideToolbar:  （Bool）是否隐藏画图工具，默认false
             colorList: （Array）颜色列表，最多8个
             lineList: （Array）线条宽度列表，最多3个
             inputPlaceholder: （String）输入框placeholder值，默认“错误描述”，多语言时使用
             proxy: （String）图片源,解决跨域问题，默认当前域名
             autoPost: （String）自动提交的异步请求地址，为空时将会执行回调，与callback必须存在一个，不然无法完成提交
             params: （Object）额外参数，当值为DOM时，获取其value值，当为值类型时，直接当做参数传递
             fileName: （String）post提交时文件的名称，默认file
             textName: （String）post提交时文本框内容的名称，默认text
             urlName: (String) post提交时当前页面链接的名称，默认url
             callBack:（Function）必传，回调函数，autoPost为空时，会把数据回调回去，autoPost不为空时，提交完成后会执行回调
             timeout:（Number）请求超时时长，默认5000，为0时不限制
    */
    window.Clairvoyance = function (element, config) {
        this.element = element;
        config = config || {};
        this.config =  {
            hideColorBar: config.hideColorBar || false,
            hideInput: config.hideInput || false,
            hideToolbar: config.hideToolbar || false,
            lineList: config.lineList || [3, 5, 7],
            colorList: config.colorList || ['#ff0000', '#ff9000', '#ffc000', '#26c800', '#00deff', '#0078ff', '#6c00ff', '#ff00fc'],
            inputPlaceholder: config.inputPlaceholder || '错误描述'
        };
        this.paramsData = config.params || {};
        this.callback = config.callback || function () { };
        this.autoPost = config.autoPost || '';
        this.fileName = config.fileName || 'file';
        this.textName = config.textName || 'text';
        this.urlName = config.urlName || 'url';
        this.timeout = config.timeout == 0 ? 0 : (config.timeout || 5000);
        this.canvasBase = null;
        this.canvasCover = null;
        this.option = {
            proxy: config.propy || location.href
        };
        this.isStart = false;
        this.startX = 0;
        this.startY = 0;
        this.endX = 0;
        this.endY = 0;
        this.area = {};
        this.canvasWidth = 0;
        this.cavnasHeight = 0;
        this.resizer = null;
        this.painter = null;
        this.toolbar = null;
        this.scriptList = {
            html2canvas: ['./html2canvas.min.js', 'https://html2canvas.hertzen.com/dist/html2canvas.min.js'],
            bluebird: ['./bluebird.min.js', 'https://cdn.jsdelivr.net/bluebird/latest/bluebird.min.js'],
        };
        var _this = this;
        this.init = function () {
            this.addCanvasToHtml();
            // this.addScriptToHtml('bluebird');
            // this.addScriptToHtml('html2canvas');
            this.element.addEventListener('click', this.elementClick);
        }
        this.closeResizer = function () { 
            this.resizer && this.resizer.close();
        };
        this.elementClick = function () {
            _this.begin();
        };
        this.complete = function () {
            const ctx = this.painter.canvas.getContext('2d');
            // 将页面生成的canvas截取并放在蒙层canvas底部
            ctx.globalCompositeOperation = 'destination-over'
            ctx.drawImage(
                this.canvasBase,
                this.area.left,
                this.area.top,
                this.area.width,
                this.area.height,
                0,
                0,
                this.area.width,
                this.area.height
            )
            var params = {};
            params[this.fileName] = this.painter.canvas.toDataURL('image/png');
            if (this.toolbar.textarea) { 
                var value = this.toolbar.textarea.value.trim();
                if (value != '') { 
                    params[this.textName] = value;
                }
            }
            this.toPost(params);
            this.handleDestroy();

            // this.option.callback && this.option.callback({ cvs, msg })
        };
        this.toPost = function (params) { 
            if (this.autoPost == '') {
                this.callback(params);
            } else { 
                var xhr = new XMLHttpRequest();
                var formData = new FormData();
				xhr.open("POST", this.autoPost, true);
                formData.append(this.fileName, params[this.fileName]);
                params[this.textName] && formData.append(this.textName, params[this.textName]);
                formData.append(this.urlName, location.href);
                var otherParamsKeys = Object.keys(this.paramsData);
                for (var i = 0; i < otherParamsKeys.length; i++) { 
                    var value = this.paramsData[otherParamsKeys[i]];
                    if (value instanceof HTMLElement) { 
                        formData.append(otherParamsKeys[i], value.value);
                    } else if(['string', 'number', 'boolean'].indexOf(typeof(value))>=0){ 
                        formData.append(otherParamsKeys[i], value);
                    }
                }
                this.timeout != 0 && (xhr.timeout = this.timeout);
                xhr.send(formData);
                xhr.onreadystatechange = function () {
                    if (xhr.readyState == 4) {
                        if (xhr.status >= 200 && xhr.status < 300 || xhr.status == 304) {
                            _this.callback(xhr.responseText);
                        } else {
                            _this.callback(xhr.responseText);
                        }
                    }
                };
                xhr.ontimeout = function (event) {
                    _this.callback('timeout');
                };
            }
        };
        this.addCanvasToHtml = function () {
            this.canvasBase = document.createElement('canvas'), this.canvasCover = document.createElement('canvas');
            this.canvasBase.id = "gyc-canvas-1";
            this.canvasCover.id = "gyc-canvas-2";
            document.body.appendChild(this.canvasBase);
            document.body.appendChild(this.canvasCover);
            // this.option.canvas = this.canvasBase;
            
        };
        this.setConfig = function (config) {
            this.painter.setConfig(config);
        };
        /*  scriptName: 要加载的脚本名称和scriptList中的name对应
            callbace: 加载完成后的回调 */
        this.addScriptToHtml = function (scriptName, callbase) {
            callbase = callbase || function () { };
            var dom = document.createElement('script');
            dom.src = this.scriptList[scriptName][1];
            document.body.appendChild(dom);
            dom.onload = function () {
                callbase();
            }
        };
        this.begin = function () {
            html2canvas(document.body, _this.option).then(function (canvas) {
                _this.canvasWidth = document.body.scrollWidth;
                _this.cavnasHeight = document.body.scrollHeight;
                var ctxt = _this.canvasCover.getContext('2d');
                var ctxb = _this.canvasBase.getContext('2d');
                _this.setAttributes(_this.canvasCover, { width: _this.canvasWidth, height: _this.cavnasHeight });
                _this.setAttributes(_this.canvasBase, { width: _this.canvasWidth, height: _this.cavnasHeight });
                _this.addBinds();
                ctxt.fillStyle = 'rgba(0,0,0,0.2)'
                ctxt.clearRect(0, 0, _this.canvasWidth, _this.cavnasHeight)
                ctxt.fillRect(0, 0, _this.canvasWidth, _this.cavnasHeight)
                ctxb.drawImage(canvas, 0, 0, _this.canvasWidth, _this.cavnasHeight)
            });
        };
        this.setAttributes = function (element, attrs) {
            attrs = attrs || {}, keysList = Object.keys(attrs);
            for (var i = 0; i < keysList.length; i++) {
                element[keysList[i]] = attrs[keysList[i]];
            }
            element.style['zIndex'] = 9999;
        };
        this.addBinds = function () {
            window.addEventListener('keydown', this.handelEsc)
            this.canvasCover.addEventListener('mousedown', this.handleMousedown)
            this.canvasCover.addEventListener('mousemove', this.handleMousemove)
            this.canvasCover.addEventListener('mouseup', this.handleMouseup)
        };
        this.handelEsc = function (e) {
            if (e.keyCode === 27) {
                _this.handleDestroy()
            }
        };
        this.handleDestroy = function () {
            this.resizer && this.resizer.handleDestroy();
            this.painter && this.painter.handleDestroy();
            this.toolbar && this.toolbar.handleDestroy();
            window.removeEventListener('keydown', this.handelEsc);
            this.area = null;
            this.resizer = null;
            this.painter = null;
            this.toolbar = null;
            var ctxt = this.canvasCover.getContext('2d');
            var ctxb = this.canvasBase.getContext('2d');
            ctxt.clearRect(0, 0, this.canvasWidth, this.cavnasHeight);
            ctxb.clearRect(0, 0, this.canvasWidth, this.cavnasHeight);
            this.canvasBase.width = 0;
            this.canvasBase.height = 0;
            this.canvasCover.width = 0;
            this.canvasCover.height = 0;
            this.canvasBase.style.zIndex = -1;
            this.canvasCover.style.zIndex = -1;
            //TODO 清除canvas
        };
        this.handleMousedown = function (e) {
            if (_this.isStart) {
                return false
            }
            _this.startX = e.offsetX
            _this.startY = e.offsetY
            _this.area = null;
            _this.isStart = true
        };
        this.handleMousemove = function (e) {
            if (!_this.isStart) {
                return false
            }
        
            _this.endX = e.offsetX
            _this.endY = e.offsetY
        
            _this.area = {
                left: Math.min(_this.endX, _this.startX),
                top: Math.min(_this.endY, _this.startY),
                width: Math.abs(_this.startX - _this.endX),
                height: Math.abs(_this.startY - _this.endY)
            }
            _this.handleResize(_this.area)
        };
        this.handleMouseup = function () {
            _this.isStart = false
            if (!_this.area) {
                return false
            }
        
            // 鼠标拖动位置长或宽小于10时，放弃本次选择
            if (_this.area.width < 10 && _this.area.height < 10) {
                return false
            }
        
            _this.finishShots()
        };
        this.finishShots = function () {
            if (!this.area) {
                return false
            }
        
            this.canvasCover.removeEventListener('mousedown', this.handleMousedown);
            this.canvasCover.removeEventListener('mousemove', this.handleMousemove);
            this.canvasCover.removeEventListener('mouseup', this.handleMouseup);
        
            this.showToolBar();
        };
        this.handleResize = function (area) {
            this.area = area;
            var ctx = this.canvasCover.getContext('2d');
            ctx.clearRect(0, 0, this.canvasWidth, this.cavnasHeight);
            ctx.fillRect(0, 0, this.canvasWidth, this.cavnasHeight);
            ctx.clearRect(area.left, area.top, area.width, area.height);
            this.painter && this.painter.handleResize(area);
            this.toolbar && this.toolbar.handleResize(area);
        };
        this.showToolBar = function () {
            this.resizer = new Resizer(this.area, this);
            this.painter = new Painter(this.area, this.config, this);
            this.toolbar = new ToolBar(this.area, this.config, this);
        };
        this.init();
    };

    function Resizer(area, superMan) {
        this.area = JSON.parse(JSON.stringify(area));
        this.pedding = null;
        this.baseDiv = null;
        this.newArea = null;
        this.points = [];
        var _this = this;
        this.superMan = superMan;
        this.init = function () {
            this.createDom();
            document.body.addEventListener('mousemove', this.handleMousemove)
            document.body.addEventListener('mouseup', this.handleMouseup)
        };
        this.handleDestroy = function () {
            document.body.removeEventListener('mousemove', this.handleMousemove);
            document.body.removeEventListener('mouseup', this.handleMouseup);
            for (var i = 0; i < this.points.length; i++) { 
                this.points[i].removeEventListener('mousedown', this.handleMousedown);
            }
            this.baseDiv.remove();
        };
        this.close = function () { 
            document.body.removeEventListener('mousemove', this.handleMousemove);
            document.body.removeEventListener('mouseup', this.handleMouseup);
            for (var i = 0; i < this.points.length; i++) { 
                this.points[i].removeEventListener('mousedown', this.handleMousedown);
                this.points[i].remove();
            }
        };
        this.handleMousemove = function (e) { 
            if (!_this.pedding) {
                return false
            }
            _this.newArea = JSON.parse(JSON.stringify(_this.area));
            var px = _this.pedding.dataset.propx;
            var py = _this.pedding.dataset.propy;
            if (py === 'top') {
                _this.newArea.top = e.pageY
                _this.newArea.height =  _this.area.height - e.pageY + _this.area.top
            } else if (py === 'height') {
                _this.newArea.height = e.pageY -  _this.area.top
            }
    
            if (px === 'width') {
                _this.newArea.width = e.pageX -  _this.area.left
            } else if (px === 'left') {
                _this.newArea.left = e.pageX
                _this.newArea.width =  _this.area.width - e.pageX +  _this.area.left
            }
    
            if (_this.newArea.width < 10 || _this.newArea.height < 10) {
                return false
            }
            _this.handleResize(_this.newArea);
        };
        this.handleResize = function (area) { 
            this.superMan.handleResize(area);
            this.setBaseDom(area);
        }
        this.handleMouseup = function () { 
            if (_this.pedding) { 
                _this.area = _this.newArea;
                _this.pedding = false;
            }
        };
        this.handleMousedown = function (e) {
            _this.pedding = e.target;
         };
        this.createDom = function () {
            this.baseDiv = document.createElement('div');
            this.baseDiv.className = 'gy-resizer-base';
            this.setBaseDom(this.area);
            document.body.appendChild(this.baseDiv);
            var pointCssList = this.getPointCssList();
            for (var i = 0; i < 8; i++) {
                var point = document.createElement('div');
                point.className = 'gy-resizer-point gy-resizer-' + (i + 1);
                this.setAttributes(point, pointCssList[i][0]);
                var dataProp = pointCssList[i][1].split(',');
                point.dataset.propx = dataProp[0].trim();
                point.dataset.propy = dataProp[1].trim();
                this.points.push(point);
                this.baseDiv.appendChild(point);
                point.addEventListener('mousedown', this.handleMousedown)
            }
        };
        this.setBaseDom = function (area) { 
            this.baseDiv.style.width = area.width + 'px';
            this.baseDiv.style.height = area.height + 'px';
            this.baseDiv.style.top = area.top + 'px';
            this.baseDiv.style.left = area.left + 'px';
        },
        this.getPointCssList = function () {
            return [
                [{ left: '0%', top: '0%', cursor: 'nw-resize'}, 'left,top'],
                [{ left: '50%', top: '0%', cursor: 's-resize'}, ',top'],
                [{ left: '100%', top: '0%', cursor: 'ne-resize'}, 'width, top'],
                [{ left: '100%', top: '50%', cursor: 'e-resize'}, 'width,'],
                [{ left: '100%', top: '100%', cursor: 'nw-resize'}, 'width, height'],
                [{ left: '50%', top: '100%', cursor: 's-resize'}, ',height'],
                [{ left: '0%', top: '100%', cursor: 'ne-resize'}, 'left,height'],
                [{ left: '0%', top: '50%', cursor: 'e-resize'}, 'left,'],
            ]
        };
        this.setAttributes = function (element, attrs) {
            attrs = attrs || {}, keysList = Object.keys(attrs);
            for (var i = 0; i < keysList.length; i++) {
                element.style[keysList[i]] = attrs[keysList[i]];
            }
        };
        this.init();
        
    }

    function Painter(area, config, superMan) { 
        this.area = JSON.parse(JSON.stringify(area));
        this.canvas = null;
        this.drawing = false;
        this.layers = [];
        var _this = this;
        this.inputDiv = null;
        this.editing = false;
        this.config = {
            lineWidth: config.lineList[0],
            strokeStyle: config.colorList[0],
            fillStyle: config.colorList[0],
            font: 'bold 8px Arial'
        };
        this.type = 'path';
        this.superMan = superMan;
        this.init = function () { 
            this.createDom();
            this.canvas.addEventListener('mouseup', this.handleMouseup)
            this.canvas.addEventListener('mousedown', this.handleMousedown)
        }
        this.setConfig = function (config) {
            if (config.type == 'line') {
                this.config.lineWidth = config.value;
            } else if (config.type == 'color') {
                this.config.strokeStyle = config.value;
                this.config.fillStyle = config.value;
            } else if (config.type == 'tool') { 
                if (config.value == 'undo') {
                    this.layers.pop()
                    this.draw()
                } else { 
                    this.type = config.value;
                }
            }
        };
        this.handleMousedown = function () { 
            _this.drawing = true
            
            if (_this.type !== 'text') {
                _this.new()
                _this.canvas.addEventListener('mousemove', _this.handleUpdate)
                _this.canvas.addEventListener('mouseup', _this.handleDone)
                _this.canvas.addEventListener('mouseleave', _this.handleDone)
            }

            // 作图后禁用缩放
            _this.superMan.closeResizer();
        };
        this.handleDone = function (e) {
            const shape = _this.layers[_this.layers.length - 1];
      
            if (_this.type !== 'text' &&
                !(shape.startPoint && shape.endPoint) &&
                !(shape.points && shape.points.length)) {
                _this.layers.pop()
            }
      
            _this.drawing = false;
            _this.canvas.removeEventListener('mousemove', _this.handleUpdate)
            _this.canvas.removeEventListener('mouseup', _this.handleDone)
            _this.canvas.removeEventListener('mouseleave', _this.handleDone)
        };
        this.handleUpdate = function (e) { 
            if (!_this.drawing) {
                return false
            }
            _this.update({x: e.offsetX, y: e.offsetY});
            _this.draw();
        };
        this.handleMouseup = function (e) { 
            if (_this.type !== 'text' || !_this.drawing || _this.editing) {
                return false
            }
            _this.new()
            const editor = _this.inputDiv;
            const canvasLeft = _this.canvas.offsetLeft + _this.canvas.offsetWidth
            const canvasTop = _this.canvas.offsetTop + _this.canvas.offsetHeight
            const width = canvasLeft - e.pageX
            const left = width < 30 ? canvasLeft - 30 : e.pageX
            const top = canvasTop - e.pageY < 24 ? canvasTop - 24 : e.pageY
            const maxHeight = canvasTop - top
        
            _this.editing = true
            editor.style.top = `${top}px`
            editor.style.left = `${left}px`
            editor.style.width = `${width}px`
            editor.style.maxHeight = `${maxHeight}px`
            editor.addEventListener('blur', _this.handleHide)
            editor.style.display = 'block';
            setTimeout(function () {
                editor.focus()
            }, 200);
        };
        this.handleChange = function (top, left, text) {
            if (!text.trim()) {
              this.layers.pop()
              return false
            }
      
            const offsetTop = top - this.canvas.offsetTop
            const offsetLeft = left - this.canvas.offsetLeft
            const maxWidth = this.canvas.offsetWidth - offsetLeft
            this.update({words: text, top:offsetTop, left:offsetLeft, width:maxWidth})
            this.draw()
        };
        this.handleHide = function (e) {
            const target = e.target
            const left = target.offsetLeft
            const top = target.offsetTop
            let text = ''

            for (var i = 0; i < target.childNodes.length; i++) { 
                text += target.childNodes[i].textContent + '\n'
            }
      
            target.innerHTML = ''
      
            _this.handleDone()
            _this.handleChange(top, left, text)
            _this.editing = false
            _this.drawing = false
            _this.inputDiv.style.display = 'none';
            _this.inputDiv.style.top = 0+'px';
            _this.inputDiv.style.left = 0+'px';
        };
        this.draw = function () {
            const ctx = this.canvas.getContext('2d');
            ctx.clearRect(0, 0, this.area.width, this.area.height);
            for (var i = 0; i < this.layers.length; i++) { 
                this.layers[i].onDraw(this.canvas);
            }
        };
        this.update = function (option) {
            const shape = this.layers[this.layers.length - 1]
            shape.onUpdate.call(shape, option);
        };
        this.shapeFactory = function () {
            switch (this.type) {
              case 'rect': return new graphs.Rect()
              case 'circle': return new graphs.Circle()
              case 'arrow': return new graphs.Arrow()
              case 'path': return new graphs.Path()
              case 'text': return new graphs.Text()
            }
        };
        this.new = function () {
            const shape = this.shapeFactory()
            shape.onConfig(this.config)
            this.layers.push(shape)
            
        };
        this.handleResize = function (area) { 
            this.canvas.width = area.width;
            this.canvas.height = area.height;
            this.canvas.style.top = area.top+1+'px';
            this.canvas.style.left = area.left+1+'px';
        };
        this.createDom = function () {
            this.canvas = document.createElement('canvas');
            this.canvas.className = 'gyc-painter-canvas';
            this.handleResize(this.area);
            document.body.appendChild(this.canvas);
            var inputDiv = document.createElement('div');
            inputDiv.className = "gy-painter-input";
            inputDiv.setAttribute('contenteditable', 'true');
            this.inputDiv = inputDiv;
            document.body.appendChild(this.inputDiv);
        };
        this.handleDestroy = function () {
            this.inputDiv.removeEventListener('blur', _this.handleHide)
            this.inputDiv.remove();
            this.canvas.removeEventListener('mouseup', this.handleMouseup);
            this.canvas.removeEventListener('mousedown', this.handleMousedown);
            this.canvas.remove();
        };
        this.init();
    }

    function ToolBar(area, option, superMan) { 
        this.area = JSON.parse(JSON.stringify(area));
        this.option = option;
        this.toolBarBase = null;
        this.textarea = null;
        this.colorBar = null;
        this.toolBar = null;
        this.addEventsList = [];
        this.superMan = superMan;
        this.toolHeight = 180;

        this.colorBarOption = {
            line: option.lineList,
            color: option.colorList
        };
        if (this.colorBarOption.line.length > 3) { 
            this.colorBarOption.line.splice(3, option.lineList.length);
        }
        if (this.colorBarOption.color.length > 8) { 
            this.colorBarOption.color.splice(8, option.colorList.length);
        }
        var toolBarOption = {
            SVG_CAMERA: '<svg t="1542180038296" class="icon" style="" viewBox="0 0 26 22" version="1.1" xmlns="http://www.w3.org/2000/svg" ' +
                'p-id="17135" xmlns:xlink="http://www.w3.org/1999/xlink" width="26" height="22"><defs><style type="text/css"></style></defs><path ' +
                'd="M1874,627a2,2,0,0,0,2-2,2.034,2.034,0,0,0-.34-1.118,2.132,2.132,0,0,0-.54-0.54,2,2,0,0,0-2.24,0,2.132,2.132,0,0,0-.54.54A2.034,2.034,' +
                '0,0,0,1872,625,2,2,0,0,0,1874,627Zm0-3a1,1,0,1,1-1,1A1,1,0,0,1,1874,624Zm1.5,6.207,3.1,3.1,2.86-4.769,2.59,5.186,0.9-.448-3.41-6.814-3.14,' +
                '5.231-2.9-2.9-4.35,4.353,0.7,0.708ZM1888,635V620h-19v-3h-1v3h-3v1h3v15h19v3h1v-3h3v-1h-3Zm-1,0h-18V621h18v14Z" ' +
                'transform="translate(-1865 -617)" p-id="17136" fill="#ffffff"  fill-rule="evenodd"></path></svg>',
            SVG_RECT: '<svg t="1539327384973" class="icon" style="" viewBox="0 0 1024 1024" version="1.1" xmlns="http://www.w3.org/2000/svg" ' +
                'p-id="4290" xmlns:xlink="http://www.w3.org/1999/xlink" width="22" height="22"><defs><style type="text/css"></style></defs><path ' +
                'd="M774 200c27.6 0 50 22.4 50 50v524c0 27.6-22.4 50-50 50H250c-27.6 0-50-22.4-50-50V250c0-27.6 22.4-50 50-50h524m0-72H250c-16.4 0-32.4 3.2-47.5 ' +
                '9.6-14.5 6.1-27.6 14.9-38.8 26.1-11.2 11.2-20 24.2-26.1 38.8-6.4 15.1-9.6 31.1-9.6 47.5v524c0 16.4 3.2 32.4 9.6 47.5 6.1 14.5 14.9 27.6 26.1 38.8 ' +
                '11.2 11.2 24.2 20 38.8 26.1 15.1 6.4 31.1 9.6 47.5 9.6h524c16.4 0 32.4-3.2 47.5-9.6 14.5-6.1 27.6-14.9 38.8-26.1 11.2-11.2 20-24.2 26.1-38.8 6.4-15.1 ' +
                '9.6-31.1 9.6-47.5V250c0-16.4-3.2-32.4-9.6-47.5-6.1-14.5-14.9-27.6-26.1-38.8-11.2-11.2-24.2-20-38.8-26.1-15.1-6.4-31.1-9.6-47.5-9.6z" p-id="4291" ' +
                'fill="#3899ff"></path></svg>',
            SVG_CIRCLE: '<svg t="1539327251392" class="icon" style="" viewBox="0 0 1024 1024" version="1.1" xmlns="http://www.w3.org/2000/svg" ' +
                'p-id="2434" xmlns:xlink="http://www.w3.org/1999/xlink" width="22" height="22"><defs><style type="text/css"></style></defs><path ' +
                'd="M512.005117 958.708971C265.683035 958.708971 65.290005 758.316965 65.290005 511.99386c0-246.310825 200.39303-446.703855 446.715111-446.703855 ' +
                '246.310825 0 446.703855 200.39303 446.703855 446.703855C958.708971 758.316965 758.316965 958.708971 512.005117 958.708971zM512.005117 ' +
                '169.716356c-188.738595 0-342.289784 153.545048-342.289784 342.277504 0 188.738595 153.551188 342.289784 342.289784 342.289784 188.733479 0 ' +
                '342.278527-153.551188 342.278527-342.289784C854.283644 323.261405 700.738595 169.716356 512.005117 169.716356z" p-id="2435" fill="#3899ff"></path></svg>',
            SVG_ARROW: '<svg t="1539564774418" class="icon" style="" viewBox="0 0 1024 1024" version="1.1" xmlns="http://www.w3.org/2000/svg" ' +
                'p-id="4408" xmlns:xlink="http://www.w3.org/1999/xlink" width="22" height="22"><defs><style type="text/css"></style></defs><path ' +
                'd="M822.66112 218.55232l-61.55264 470.9376c-0.45056 3.45088-2.03776 6.53312-4.37248 8.86784-2.304 2.304-5.3248 3.87072-8.72448 4.352-6.83008 ' +
                '0.96256-13.47584-2.7648-16.22016-9.10336l-81.99168-189.07136L336.03584 818.29888c-6.00064 6.00064-15.72864 6.00064-21.72928 0L205.70112 ' +
                '709.6832c-6.00064-6.00064-6.00064-15.7184 0-21.71904l313.76384-313.76384-189.07136-81.99168c-6.33856-2.75456-10.06592-9.39008-9.10336-16.2304 ' +
                '0.95232-6.84032 6.3488-12.20608 13.21984-13.09696l470.92736-61.55264c4.73088-0.62464 9.48224 0.99328 12.8512 4.36224C821.66784 209.07008 823.28576 ' +
                '213.82144 822.66112 218.55232z" p-id="4409" fill="#3899ff"></path></svg>',
            SVG_PATH: '<svg t="1539566661169" class="icon" style="" viewBox="0 0 1024 1024" version="1.1" xmlns="http://www.w3.org/2000/svg" ' +
                'p-id="4922" xmlns:xlink="http://www.w3.org/1999/xlink" width="22" height="22"><defs><style type="text/css"></style></defs><path ' +
                'd="M819 190.3c-26.7-26.4-70.1-26.4-96.8 0L437.9 471.1c-3.8 3.8-3.9 10 0 13.8l82.4 82.4c3.8 3.8 9.9 3.8 13.7 0l285-281.5c26.8-26.3 26.8-69.1 ' +
                '0-95.5zM404.9 517.2c-3.8-3.8-9.9-3.8-13.7 0l-63 62.1c-1.8 1.8-4.3 2.8-6.8 2.8-48.1-0.1-112.4 18.7-140.8 110.7-0.1 0.4-0.3 0.8-0.4 1.2-14.1 ' +
                '31.3-42.2 41.9-61.2 45.5-7.7 1.5-10.7 11-5 16.5 118.1 114.1 251.5 42.3 282.9 10.5 27.2-27.6 32.3-61 30.2-88.6-0.2-2.9 0.8-5.7 2.9-7.7l57.5-56.7c3.8-3.8 ' +
                '3.9-10 0-13.8l-82.6-82.5z m-40.3 217.4c-21.4 19.8-112.7 62.7-173.2 29.6-5.6-3.1-6.7-10.6-2.4-15.2 7.5-7.8 18.5-21.2 27.8-40.4 0.1-0.3 0.2-0.5 0.4-0.8 ' +
                '33.3-87.9 110.1-86.6 127.7-85.2 2.3 0.2 4.4 1.2 6 2.8l29.9 29.5c0.2 0.4 24 42.4-16.2 79.7z" p-id="4923" fill="#3899ff"></path></svg>',
            SVG_TEXT: '<svg t="1539567466254" class="icon" style="" viewBox="0 0 1024 1024" version="1.1" xmlns="http://www.w3.org/2000/svg" ' +
                'p-id="3427" xmlns:xlink="http://www.w3.org/1999/xlink" width="22" height="22"><defs><style type="text/css"></style></defs><path ' +
                'd="M183.215629 864.706177l657.565673 0 0-93.912809-657.565673 0L183.215629 864.706177zM394.589546 573.46636l234.88947 0 42.252271 103.341543 ' +
                '98.662992 0-220.792418-516.65962-70.457631 0-225.465853 516.65962 98.5975 0L394.589546 573.46636zM512.039397 254.071326l89.233235 234.834212-173.800198 ' +
                '0L512.039397 254.071326z" p-id="3428" fill="#3899ff"></path></svg>',
            SVG_UNDO: '<svg t="1539566377901" class="icon" style="" viewBox="0 0 1024 1024" version="1.1" xmlns="http://www.w3.org/2000/svg" ' +
                'p-id="2253" xmlns:xlink="http://www.w3.org/1999/xlink" width="22" height="22"><defs><style type="text/css"></style></defs><path ' +
                'd="M895.8 736.4c0-33.6 7.2-166.2-97.4-271.4-70.4-70.8-160.6-106.8-286.6-112.4V192L128 448l384 256V544.4c80 2.2 124.8 18.2 173.4 40C747.2 612 ' +
                '796 672.4 837 737.6l38.4 62.4H896c0-20.2-0.2-45.8-0.2-63.6z" p-id="2254" fill="#3899ff"></path></svg>',
            SVG_CANCEL: '<svg t="1539567144686" class="icon" style="" viewBox="0 0 1024 1024" version="1.1" xmlns="http://www.w3.org/2000/svg" ' +
                'p-id="7539" xmlns:xlink="http://www.w3.org/1999/xlink" width="22" height="22"><defs><style type="text/css"></style></defs><path ' +
                'd="M832 742.4 601.6 512 825.6 288 736 198.4 512 422.4 281.6 192 192 281.6 422.4 512 198.4 736 288 825.6 512 601.6 742.4 832Z" p-id="7540" ' +
                'fill="#ed4014"></path></svg>',
            SVG_COMPLETE: '<svg t="1539567240692" class="icon" style="" viewBox="0 0 1024 1024" version="1.1" xmlns="http://www.w3.org/2000/svg" ' +
                'p-id="9441" xmlns:xlink="http://www.w3.org/1999/xlink" width="22" height="22"><defs><style type="text/css"></style></defs><path ' +
                'd="M933.568 211.008c-27.072-28.096-71.232-28.096-98.304 0.128l-474.816 492.096L213.12 550.656c-27.2-28.16-71.232-28.16-98.432-0.064-27.008 ' +
                '28.096-27.008 73.664 0 101.952l196.864 203.904c27.008 28.096 71.104 28.096 98.304 0.128 0.512-0.576 0.704-1.344 1.216-1.92l522.56-541.632C960.64 ' +
                '284.8 960.64 239.232 933.568 211.008z" p-id="9442" fill="#19be6b"></path></svg>',
            SVG_TOP: '<svg t="1542181170450" class="icon" style="" version="1.1" xmlns="http://www.w3.org/2000/svg" p-id="18398" ' +
                'xmlns:xlink="http://www.w3.org/1999/xlink" width="21" height="22" viewBox="0 0 21 22"><defs><style type="text/css"></style></defs><path d="M1877.66,662.692l-7.01,7.162,' +
                '7.01-7.163,8.94,9.145-8.94-9.144v0Zm0-.713h0l-0.7.712h0l-9.32,9.528,0.7,0.711,8.83-9.024v19.059h0.98V663.907l8.83,9.024,0.69-.711-9.31-9.528h0l-0.7-.712h0Z" ' +
                'transform="translate(-1867.66 -661.969)" p-id="18399" fill="#ffffff"  fill-rule="evenodd"></path></svg>'
        };
        var shapes = {
            rect: toolBarOption.SVG_RECT,
            circle: toolBarOption.SVG_CIRCLE,
            arrow: toolBarOption.SVG_ARROW,
            path: toolBarOption.SVG_PATH,
            text: toolBarOption.SVG_TEXT
        };
        var actions = {
            undo: toolBarOption.SVG_UNDO,
            cancel: toolBarOption.SVG_CANCEL,
            complete: toolBarOption.SVG_COMPLETE
        };
        var _this = this;
        this.init = function () {
            this.createDom();
        };
        this.handleDestroy = function () {
            for (var i = 0; i < this.addEventsList.length; i++) { 
                this.addEventsList[i].removeEventListener('click', this.lineAndColorClick);
            }
            this.toolBarBase.remove();
        };
        /* 工具位置设置 */
        this.handleResize = function (area) {
            this.toolBarBase.style.top = (area.top <= this.toolHeight ? area.top + area.height + 22 : area.top - (this.toolHeight-30)) + 'px';
            this.toolBarBase.style.left = (area.left + area.width - 336 >= 20 ? area.left + area.width - 334 : area.left) + 'px';
        };
        /* 工具模块创建 */
        this.createDom = function () { 
            var toolBarBase = document.createElement('div');
            toolBarBase.className = 'gyc-toolbar-base';
            this.toolBarBase = toolBarBase;
            if (!this.option.hideInput) {
                var textarea = document.createElement('textarea');
                textarea.className = 'gyc-toolbar-textarea';
                textarea.placeholder = this.option.inputPlaceholder;
                toolBarBase.appendChild(textarea);
                this.textarea = textarea;
            } else { 
                this.toolHeight -= 40;
            }
            if (!this.option.hideColorBar) {
                var colorBar = document.createElement('div');
                colorBar.className = 'gyc-toolbar-colorbar';
                if (!this.option.hideToolbar) { 
                    colorBar.className += ' show-tool';
                }
                toolBarBase.appendChild(colorBar);
                this.colorBar = colorBar;
                this.createColorBar();
            } else { 
                this.toolHeight -= 40;
            }
            if (!this.option.hideToolbar) { 
                var toolBar = document.createElement('div');
                toolBar.className = 'gyc-toolbar-toolbar';
                toolBarBase.appendChild(toolBar);
                this.toolBar = toolBar;
                this.createToolBar();
            } else { 
                this.toolHeight -= 58;
            }
            this.handleResize(this.area);
            document.body.appendChild(toolBarBase);
        };
        this.createColorBar = function () { 
            /* 线条宽度工具创建 */
            var colorBarLineBase = document.createElement('div'), eventList = [];
            colorBarLineBase.className = 'gyc-toolbar-colorbar-lines';
            for (var i = 0; i < this.colorBarOption.line.length; i++) { 
                var line = document.createElement('a');
                line.href = "javascript:;";
                line.className = 'gyc-toolbar-colorbar-line gyc-toolbar-colorbar-line-' + (i + 1);
                line.innerHTML = "<span></span>";
                line.dataset.value = this.colorBarOption.line[i];
                line.dataset.type = 'line';
                if (i == 0) { 
                    line.className += ' select';
                }
                colorBarLineBase.appendChild(line);
                this.addEventsList.push(line);
                eventList.push(line);
            }
            /* 线条颜色工具创建 */
            var colorBarColorBase = document.createElement('div');
            colorBarColorBase.className = 'gyc-toolbar-colorbar-colors';
            for (var i = 0; i < this.colorBarOption.color.length; i++) { 
                var color = document.createElement('a');
                color.href = "javascript:;";
                color.className = 'gyc-toolbar-colorbar-color gyc-toolbar-colorbar-color-' + (i + 1);
                color.innerHTML = '<span style="background-color: '+this.colorBarOption.color[i]+'"></span>';
                color.dataset.value = this.colorBarOption.color[i];
                color.dataset.type = 'color';
                if (i == 0) { 
                    color.className += ' select';
                }
                colorBarColorBase.appendChild(color);
                this.addEventsList.push(color);
                eventList.push(color);
            }
            this.colorBar.appendChild(colorBarLineBase);
            this.colorBar.appendChild(colorBarColorBase);
            this.addBinds(eventList);
        };
        /* 绑定工具模块的各个事件 */
        this.addBinds = function (eventList) { 
            for (var i = 0; i < eventList.length; i++) { 
                eventList[i].addEventListener('click', this.lineAndColorClick);
            }
        };
        this.cancel = function () {
            this.superMan.handleDestroy();
        };
        this.complete = function () { 
            this.superMan.complete();
        };
        this.lineAndColorClick = function () {
            if (this.dataset.value == 'cancel') { 
                _this.cancel();
                return;
            } else if (this.dataset.value == 'complete') { 
                _this.complete();
                return;
            }
            _this.superMan.setConfig(this.dataset);
            if (this.dataset.value != 'undo') { 
                var className = 'gyc-toolbar-toolbar-tool'
                if (this.dataset.type == "line") {
                    className = 'gyc-toolbar-colorbar-line'
                } else if (this.dataset.type == 'color') {
                    className = 'gyc-toolbar-colorbar-color'
                }
                if (this.className.indexOf('select') < 0) { 
                    _this.removeClass(document.getElementsByClassName(className + ' select')[0], 'select');
                    this.className += ' select';
                }
            }
        };
        this.removeClass = function(el, className){ 
            var classNameList = el.className.split(' ');
            classNameList.splice(classNameList.indexOf('select'), 1);
            el.className = classNameList.join(' ');
        };
        /* 工具样式创建 */
        this.createToolBar = function () { 
            var shapesKeys = Object.keys(shapes), actionsKeys = Object.keys(actions), eventList = [];
            for (var i = 0; i < shapesKeys.length; i++) { 
                var tool = document.createElement('a');
                tool.href = "javascript:;";
                tool.className = 'gyc-toolbar-toolbar-tool gyc-toolbar-toolbar-shapes-' + (i + 1);
                tool.innerHTML = shapes[shapesKeys[i]];
                tool.dataset.value = shapesKeys[i];
                tool.dataset.type = 'tool';
                this.toolBar.appendChild(tool);
                if (shapesKeys[i] == 'path') { 
                    tool.className += ' select';
                }
                this.addEventsList.push(tool);
                eventList.push(tool);
            }
            for (var i = 0; i < actionsKeys.length; i++) { 
                var tool = document.createElement('a');
                tool.href = "javascript:;";
                tool.className = 'gyc-toolbar-toolbar-tool gyc-toolbar-toolbar-actions-' + (i + 1);
                tool.innerHTML = actions[actionsKeys[i]];
                tool.dataset.value = actionsKeys[i];
                tool.dataset.type = 'tool';
                this.toolBar.appendChild(tool);
                this.addEventsList.push(tool);
                eventList.push(tool);
            }
            this.addBinds(eventList);
        };
        this.init();
    }
    
    const Graph = (function () { 
        function constructor () {
            this.config = {}
        }
        const needImpelement = (func) => {
            throw new Error(func + ' need impelement')
        }
        constructor.prototype.onDraw = needImpelement.bind(null, 'onDraw')
        constructor.prototype.onUpdate = needImpelement.bind(null, 'onUpdate')
        constructor.prototype.onConfig = function (config) {
            this.config = Object.assign({}, this.config, config)
        }
        constructor.prototype.getCustomContext = function (canvas) {
            const context = canvas.getContext('2d')
            var keys = Object.keys(this.config);
            for (var i = 0; i < keys.length; i++) { 
                context[keys[i]] = this.config[keys[i]];
            }
            return context
        }
        return constructor
    })();
    const graphs = {
        Rect: (function () { 
            function constructor() { 
                this.startPoint = null;
                this.endPoint = null;
                this.onUpdate = function (option) {
                    if (!this.startPoint) {
                        this.startPoint = [option.x, option.y];
                    } else {
                        this.endPoint = [option.x, option.y];
                    }
                }
                this.onDraw = function (canvas) {
                    if (!this.startPoint || !this.endPoint) {
                        return
                    }
                    const context = this.getCustomContext(canvas);
                    context.strokeRect(
                        this.startPoint[0],
                        this.startPoint[1],
                        this.endPoint[0] - this.startPoint[0],
                        this.endPoint[1] - this.startPoint[1]
                    );
                }
            };
            constructor.prototype = new Graph();
            return constructor;
        })(),
        Circle: (function () { 
            function constructor() { 
                this.startPoint = null;
                this.endPoint = null;
                this.onUpdate = function (option) {
                    if (!this.startPoint) {
                        this.startPoint = [option.x, option.y];
                    } else {
                        this.endPoint = [option.x, option.y];
                    }
                }
                this.onDraw = function (canvas) {
                    if (!this.startPoint || !this.endPoint) {
                        return
                    }
                    const context = this.getCustomContext(canvas)
                
                    // 长轴短轴
                    const a = this.endPoint[0] - this.startPoint[0]
                    const b = this.endPoint[1] - this.startPoint[1]
                
                    // 圆心
                    const x = this.startPoint[0] + a / 2
                    const y = this.startPoint[1] + b / 2
                
                    // draw circle
                    context.beginPath()
                    context.ellipse(x, y, Math.abs(a / 2), Math.abs(b / 2), 0, 0, 2 * Math.PI)
                    context.closePath()
                    context.stroke()
                }
            };
            constructor.prototype = new Graph();
            return constructor;
        })(),
        Arrow: (function () { 
            function constructor() { 
                this.startPoint = null;
                this.endPoint = null;
                this.onUpdate = function (option) {
                    if (!this.startPoint) {
                        this.startPoint = [option.x, option.y];
                    } else {
                        this.endPoint = [option.x, option.y];
                    }
                }
                this.onDraw = function (canvas) {
                    if (!this.startPoint || !this.endPoint) {
                        return
                    }
                    const context = this.getCustomContext(canvas)
                
                    // 当连线距离过小时调整箭头三角形大小
                    const trigonResize = function(self) {
                        const x = self.endPoint[0] - self.startPoint[0]
                        const y = self.endPoint[1] - self.startPoint[1]
                        const length = Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2))
                
                        if (length < 50) {
                            consts.edgeLen = consts.edgeLen / 2
                            consts.angle = consts.angle / 2
                        } else if (length < 100) {
                            consts.edgeLen = consts.edgeLen * length / 100
                            consts.angle = consts.angle * length / 100
                        }
                    }
                
                    // 箭头三角形边长与夹角
                    const consts = {
                        edgeLen: context.lineWidth < 5 ? 10 : (context.lineWidth < 7 ? 20 : 30),
                        angle: 25
                    }
                
                    // 起点终点连线与x轴夹角
                    const lineAngle = Math.atan2(
                        this.endPoint[1] - this.startPoint[1],
                        this.endPoint[0] - this.startPoint[0]
                    ) / Math.PI * 180
                    trigonResize(this)
                
                    // 箭头6个点数组
                    const points = []
                    const midPoint = []
                
                    points[0] = this.startPoint[0]
                    points[1] = this.startPoint[1]
                    points[6] = this.endPoint[0]
                    points[7] = this.endPoint[1]
                    points[8] = this.endPoint[0] - consts.edgeLen * Math.cos(
                        Math.PI / 180 * (lineAngle + consts.angle))
                    points[9] = this.endPoint[1] - consts.edgeLen * Math.sin(
                        Math.PI / 180 * (lineAngle + consts.angle))
                    points[4] = this.endPoint[0] - consts.edgeLen * Math.cos(
                        Math.PI / 180 * (lineAngle - consts.angle))
                    points[5] = this.endPoint[1] - consts.edgeLen * Math.sin(
                        Math.PI / 180 * (lineAngle - consts.angle))
                    midPoint[0] = (points[4] + points[8]) / 2
                    midPoint[1] = (points[5] + points[9]) / 2
                    points[2] = (points[4] + midPoint[0]) / 2
                    points[3] = (points[5] + midPoint[1]) / 2
                    points[10] = (points[8] + midPoint[0]) / 2
                    points[11] = (points[9] + midPoint[1]) / 2
                
                    // 画箭头
                    context.beginPath()
                    context.moveTo(points[0], points[1])
                    context.lineTo(points[2], points[3])
                    context.lineTo(points[4], points[5])
                    context.lineTo(points[6], points[7])
                    context.lineTo(points[8], points[9])
                    context.lineTo(points[10], points[11])
                    context.closePath()
                    context.fill()
                }
            };
            constructor.prototype = new Graph();
            return constructor;
        })(),
        Text: (function () { 
            function constructor() { 
                this.words = ''
                this.config = {
                    textAlign: 'left',
                    textBaseline: 'middle'
                }
                this.onUpdate = function (option) {
                    this.words = option.words
                    this.left = option.left
                    this.top = option.top
                    this.width = option.width
                }
                this.onDraw = function (canvas) {
                    const ctx = this.getCustomContext(canvas)
                    let lines = 0;
                    var wordsList = this.words.split('\n');
                    for (var i = 0; i < wordsList.length; i++) { 
                        var word = wordsList[i];
                        const chars = word.split('')
                        const rows = []
                        const size = /(\d+)/.exec(this.config.font)[0]
                        let temp = ''
                        for (var j = 0; j < chars.length; j++) { 
                            if (ctx.measureText(temp).width >= this.width) {
                                rows.push(temp)
                                temp = ''
                            }
                            temp += chars[j];
                        }
                        rows.push(temp)
                        for (var z = 0; z < rows.length; z++) { 
                            ctx.fillText(rows[z], this.left, this.top + size * lines)
                            lines++
                        }
                    }
                }
            };
            constructor.prototype = new Graph();
            return constructor;
        })(),
        Path: (function () { 
            function constructor() { 
                this.points = [];
                this.onUpdate = function (option) {
                    this.points.push([option.x, option.y]);
                }
                this.onDraw = function (canvas) {
                    const context = this.getCustomContext(canvas)
                    context.beginPath()
                    for (var index = 0; index < this.points.length; index++) { 
                        var item = this.points[index];
                        if (index === 0) {
                            context.moveTo(item[0], item[1]);
                        } else { 
                            context.lineTo(item[0], item[1])
                        }
                    }
                    context.stroke()
                }
            };
            constructor.prototype = new Graph();
            return constructor;
        })()
    }
}());