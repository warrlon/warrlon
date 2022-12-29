# 边缘节点部署管理

## 部署边缘节点配置

功能描述：将边缘节点配置（关联设备、边缘节点通道等）下发至边缘节点。

```
POST  /api/v1/gateway/deploy/{id}
```

**Query:**

| Name      | Description | Required | Type | marks |
| --------- | ----------- | -------- | ---- | ----- |
| gatewayId | 边缘节点 ID | Yes      | int  |       |



**Responses:**

```
{
    "success": true,
    "code": 0,
    "msg": "",
    "data": null
}
```



------

## 部署边缘节点检查

功能描述：将边缘节点配置（关联设备、网关通道等）下发至边缘节点的检查。

```
POST  /api/v1/command/gateway/deploy/check/id/{id}
```

**Query:**

| Name      | Description | Required | Type | marks |
| --------- | ----------- | -------- | ---- | ----- |
| gatewayId | 边缘节点 ID | Yes      | int  |       |



**Responses:**

```
{
    "success": true,
    "code": 0,
    "msg": "",
    "data": true
}
```



------

## 获取边缘节点mqtt broker地址
```
GET  /api/v1/edge/node/mqtt/broker
```

**Responses:**

```
{
    "success": true,
    "code": 0,
    "msg": "",
    "data": "http://xxxx"
}

```
