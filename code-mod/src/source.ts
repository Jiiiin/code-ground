import { Component, OnInit } from '@angular/core';
import { FormGroup, FormControl, FormBuilder, Validators } from '@angular/forms';
import { FieldType } from 'paletx/plx-form/form.model';

@Component({
  selector: 'plx-form-basic',
  templateUrl: './form-basic.html'
})
export class PlxFormBasic implements OnInit {
    constructor() {}
  formSetting: any;

  ngOnInit(): void {
    this.formSetting = {
      isShowHeader: true,
      header: '表单示例',
      isGroup: true,
      srcObj: {
        id: 1,
        //authType: '0'
      },
      buttons: [
        {
          type: 'submit',
          label: '确定',
          class: 'plx-btn plx-btn-primary plx-space-md-t',
          hidden: false,
          disabled: false,
          callback: (values, $event, controls) => {
            this.doSubmit(values, $event, controls);
          }
        },
        {
          type: 'cancel',
          label: '取消',
          placement: "top-left",
          plxPopover: "取消",
          class: 'plx-btn plx-space-md-t',
          hidden: false,
          disabled: false,
          callback: (values, $event, controls) => {
            alert('你点了取消？data=' + JSON.stringify(values));
          }
        }
      ],
      fieldSet: [
        {
          group: '基本信息',
          fields: [
            {
              name: 'id',
              label: '编号',
              type: FieldType.NUMBER,
              //placeholder: '请输入数字',
              required: true,
              step: 0.1,
              max: 60,
              precision: 1,
              validators: [Validators.max(60)],
              validateInfos: {
                'max': '编号最大值是60',
              },
              help: '请输入数字',
              outputs: {
                click: () => {
                  console.log('Im opened');
                }
              },
              callback: (values, $event, controls) => {
                console.log('twst');
                this.formSetting.fieldMap.name.required = values.id === 0;
              }
            },
            {
              name: 'name',
              label: '名称',
              type: FieldType.STRING,
              forbiddenCharacter: '%@!',
              placeholder: '支持字母、数字、"_"、"-"的组合，4-20个字符',
              required: true,
              maxLength: 20, //maxLength:20 和 下面的Validators.maxLength(20)是两个独立的校验项。前者直接限制输入，后者允许输入但会提示错误
              validators: [Validators.pattern(/^[a-zA-Z0-9_-]{4,20}$/), Validators.minLength(4), Validators.maxLength(20)],
              validateInfos: {
                'required': '名称必须输入',
                'pattern': '名称只能输入字母、数字、"_"、"-"的组合，4-20个字符'
              },
              binding: {
                prefix: 'https://',
                width: '100%',
              }
            }
          ]
        },
        {
          group: '认证信息',
          fields: [
            {
              name: 'authType',
              label: '认证方式',
              type: FieldType.SELECTOR,
              required: true,
              validators: [],
              placeholder: '请选择',
              multiple: true,
              valueSet: [
                {
                  label: '无认证',
                  value: '0'
                },
                {
                  label: '单向认证',
                  value: '1'
                },
                {
                  label: '双向认证',
                  value: '2'
                },
              ],
              validateInfos: {
                'required': '认证方式必须输入'
              },
              notFoundMsg: '没有找到数据',
            },
            {
              name: 'apiUrl',
              label: '接入URL',
              type: FieldType.STRING,
              placeholder: '输入格式如http://192.168.0.1:8080/v2.0',
              required: true,
              validators: [Validators.pattern(/^(h|H)(t|T)(t|T)(p|P)((s|S){0,1})/)],
              validateInfos: {
                'pattern': '接入URL输入格式不正确'
              },
              hidden: (values: any, controls: any) => {
                return values.authType === '0';
              }
            },
            {
              name: 'version',
              label: '版本号',
              type: FieldType.STRING,
              required: true,
              hidden: (values: any, controls: any) => {
                return values.authType === '1';
              }
            },
            {
              name: 'password',
              label: '密码',
              type: FieldType.PASSWORD,
              passwordSwitch: true
            },
            {
              name: 'longLabel',
              label: '超长文本标签超长文本标签超长文本标签超长文本标签超长文本标签超长文本标签',
              type: FieldType.STRING
            }
          ]
        }

      ]
    };

  }


  doSubmit(values: any, $event: any, controls): void {
    alert('您已提交！data=' + JSON.stringify(values));
  }

}